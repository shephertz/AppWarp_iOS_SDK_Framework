//
//  TestClassViewController.m
//  AppWarp_Sample
//
//  Created by Shephertz Technology on 08/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import "TestClassViewController.h"

#import <AppWarp_iOS_SDK/AppWarp_iOS_SDK.h>
#import "RoomListener.h"
#import "NotificationListener.h"
#import "LobbyListener.h"

@interface TestClassViewController ()

@end

@implementation TestClassViewController



@synthesize usernameTextField,resultLabel,roomId;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}

-(void)updateResultLabel:(NSString*)message{
    resultLabel.text = message;
}

-(IBAction)lobbyButtonClicked:(id)sender{
    NSLog(@"lobbyButtonClicked");
    [usernameTextField resignFirstResponder];
    if ([[WarpClient getInstance] getConnectionState] == AUTHENTICATED) {
        [[WarpClient getInstance]joinLobby];
    }
    else{
        NSLog(@"please join zone first");
    }
    
}
-(IBAction)chatButtonClicked:(id)sender{
    NSLog(@"chat button clicked");
    [usernameTextField resignFirstResponder];
    if ([[WarpClient getInstance] getConnectionState] == AUTHENTICATED) {
        [[WarpClient getInstance]sendChat:@"hello world"];
    }
    else{
        NSLog(@"please join zone first");
    }
}

-(IBAction)roomCallsClicked:(id)sender{
    [usernameTextField resignFirstResponder];
    if ([[WarpClient getInstance] getConnectionState] == AUTHENTICATED) {
        [[WarpClient getInstance]createRoomWithRoomName:usernameTextField.text roomOwner:@"Shephertz" maxUsers:3];
    }
    else {
        NSLog(@"please join zone first");
    }
}


-(IBAction)AuthClicked:(id)sender{
    NSLog(@"Auth clicked");
    [usernameTextField resignFirstResponder];
    
    // Please replace with the API and Secret key pair received after registering
    [WarpClient initWarp:@"" secretKey:@""];
    
    WarpClient *warpClient = [WarpClient getInstance];
    [warpClient addConnectionRequestListener:self];
    [warpClient addZoneRequestListener:self];
    
    RoomListener *roomListener = [[RoomListener alloc]initWithViewController:self];
    [warpClient addRoomRequestListener:roomListener];
    
    NotificationListener *notificationListener = [[NotificationListener alloc]initWithViewController:self];
    [warpClient addNotificationListener:notificationListener];
    
    LobbyListener *lobbyListener = [[LobbyListener alloc]initWithViewController:self];
    [warpClient addLobbyRequestListener:lobbyListener];
    
    [warpClient connect];
}

-(void)onConnectDone:(ConnectEvent*) event{
    if (event.result==0) {
        resultLabel.text = @"Connection Done";
        NSLog(@"userNameTextField.text = %@",usernameTextField.text);
        [[WarpClient getInstance]joinZone:usernameTextField.text];
    }
    else {
        NSLog(@"connection failed");
    }
}

-(void)onJoinZoneDone:(ConnectEvent*) event{
    if (event.result==0) {
        resultLabel.text = @"Join Zone Done";
        NSLog(@"Join Zone done");
        
    }
    else {
        NSLog(@"Join Zone failed");
    }
}


-(void)onDisconnectDone:(ConnectEvent*) event{
    NSLog(@"connection failed");
}

#pragma mark ------
#pragma ZoneListener Protocol methods


-(void)onCreateRoomDone:(RoomEvent*)roomEvent{
    RoomData *roomData = roomEvent.roomData;
    NSLog(@"roomEvent result = %i",roomEvent.result);
    NSLog(@"room id = %@",roomData.roomId);
    
    [[WarpClient getInstance]getAllRooms];
}

-(void)onDeleteRoomDone:(RoomEvent*)roomEvent{
    if (roomEvent.result == SUCCESS) {
        [self updateResultLabel:@"Room Deleted"];
    }
    else {
        [self updateResultLabel:@"Room Deleted failed"];
    }
}

-(void)onGetAllRoomsDone:(AllRoomsEvent*)event{
    if (event.result == SUCCESS) {
        [self updateResultLabel:@"All Rooms Get"];
        [[WarpClient getInstance]getOnlineUsers];
    }
    else {
        [self updateResultLabel:@"All Rooms Get failed"];
    }
}
-(void)onGetOnlineUsersDone:(AllUsersEvent*)event{
    if (event.result == SUCCESS) {
        [self updateResultLabel:@"All Online Users Get Operation"];
        NSLog(@"usernames = %@",event.userNames);
    }
    else {
        [self updateResultLabel:@"All Online Users Get Operation failed"];
    }
    
}
-(void)onGetLiveUserInfoDone:(LiveUserInfoEvent*)event{
    NSLog(@"onGetLiveUserInfo called");
    if (event.result == SUCCESS) {
        [self updateResultLabel:@"Get Live user info done"];
        [[WarpClient getInstance]setCustomUserData:event.name customData:usernameTextField.text];
    }
    else {
        [self updateResultLabel:@"Get live user info failed"];
    }
    
}
-(void)onSetCustomUserDataDone:(LiveUserInfoEvent*)event{
    if (event.result == SUCCESS) {
        [self updateResultLabel:event.customData];
    }
    else {
        [self updateResultLabel:@"custom data not set"];
    }
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

@end
