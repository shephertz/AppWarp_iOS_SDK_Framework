//
//  ViewController.m
//  AppWarp_iOS_Sample
//
//  Created by shephertz technologies on 22/05/13.
//  Copyright (c) 2013 shephertz technologies. All rights reserved.
//

#import "ViewController.h"
#import <AppWarp_iOS_SDK/AppWarp_iOS_SDK.h>
#import "ConnectionListener.h"
#import "RoomListener.h"
#import "NotificationListener.h"
#import "ZoneListener.h"
#import "LobbyListener.h"
#import "ChatListener.h"

#define APPWARP_APP_KEY     @"cad2bfab6310acd9696187b98682925125e469ab0d0d585db0b00609f461b791"
#define APPWARP_SECRET_KEY  @"55811709916e7ce4405cde0cdc5a254cf4b506fbafdae05760a73100b8080b67"

@interface ViewController ()

@end

@implementation ViewController
@synthesize roomId;

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    
    [nameTextField setDelegate:self];
    [roomNameTextField setDelegate:self];
    [roomOwnerTextField setDelegate:self];
    [maxUserTextField setDelegate:self];
    [property1KeyTextField setDelegate:self];
    [property2KeyTextField setDelegate:self];
    [property3KeyTextField setDelegate:self];
    [property1ValueTextField setDelegate:self];
    [property2ValueTextField setDelegate:self];
    [property3ValueTextField setDelegate:self];
    
    [self initializeAppWarp];
}

-(void)initializeAppWarp
{
    [WarpClient initWarp:APPWARP_APP_KEY secretKey:APPWARP_SECRET_KEY];
    
    WarpClient *warpClient = [WarpClient getInstance];
    
    [warpClient enableTrace:YES];
    
    ConnectionListener *connectionListener = [[ConnectionListener alloc] initWithHelper:self];
    [warpClient addConnectionRequestListener:connectionListener];
    [connectionListener release];
    
    ZoneListener *zoneListener = [[ZoneListener alloc] initWithHelper:self];
    [warpClient addZoneRequestListener:zoneListener];
    [zoneListener release];
    
    RoomListener *roomListener = [[RoomListener alloc]initWithHelper:self];
    [warpClient addRoomRequestListener:roomListener];
    [roomListener release];
    
    NotificationListener *notificationListener = [[NotificationListener alloc]initWithHelper:self];
    [warpClient addNotificationListener:notificationListener];
    [notificationListener release];
    
    LobbyListener *lobbyListener = [[LobbyListener alloc]initWithHelper:self];
    [warpClient addLobbyRequestListener:lobbyListener];
    [lobbyListener release];
    
    ChatListener *chatListener = [[ChatListener alloc]initWithHelper:self];
    [warpClient addChatRequestListener:chatListener];
    [chatListener release];
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)showAlertWithInfo:(NSDictionary*)alertInfo
{
    UIAlertView *alert = [[UIAlertView alloc]
                          initWithTitle: [alertInfo objectForKey:@"title"]
                          message:[alertInfo objectForKey:@"message"]
                          delegate: nil
                          cancelButtonTitle:@"OK"
                          otherButtonTitles:nil];
    [alert show];
    [alert release];
}

-(void)updateResponseLabel:(NSString*)responseString
{
    [response setText:responseString];
}

#pragma mark -- Button Actions -- 

-(IBAction)connectButtonAction:(id)sender
{
    [[WarpClient getInstance] connectWithUserName:nameTextField.text];
    [nameTextField resignFirstResponder];
}


-(IBAction)disConnectButtonAction:(id)sender
{
    [[WarpClient getInstance] disconnect];
}


-(IBAction)createRoomButtonAction:(id)sender
{
    [createRoomView setHidden:NO];
    [self.view bringSubviewToFront:createRoomView];
}

-(IBAction)updateRoomProperty:(id)sender
{
     NSMutableDictionary *properties=[NSMutableDictionary dictionaryWithObjectsAndKeys:@"Rajeev",@"Name", nil];
    
    [[WarpClient getInstance] updateRoom:[NSString stringWithFormat:@"%@",roomId] addProperties:properties removeProperties:nil];
}

-(IBAction)createButtonAction:(id)sender
{
    
    NSMutableDictionary *properties=[NSMutableDictionary dictionaryWithCapacity:0];
    
    NSString *key = property1KeyTextField.text;
    NSString *value = property1ValueTextField.text;
    
    if (key && value && key.length && value.length)
    {
        [properties setObject:key forKey:value];
    }
    
    key = property2KeyTextField.text;
    value = property2ValueTextField.text;
    
    if (key && value && key.length && value.length)
    {
        [properties setObject:key forKey:value];
    }
    
    key = property3KeyTextField.text;
    value = property3ValueTextField.text;
    
    if (key && value && key.length && value.length)
    {
        [properties setObject:key forKey:value];
    }
    
    [[WarpClient getInstance] createRoomWithRoomName:roomNameTextField.text roomOwner:roomOwnerTextField.text properties:properties maxUsers:[maxUserTextField.text intValue]];

    [createRoomView setHidden:YES];
    
}


-(IBAction)joinRoomButtonAction:(id)sender
{
    [[WarpClient getInstance] joinRoom:roomId];
}

-(IBAction)joinLobbyButtonAction:(id)sender
{
    [[WarpClient getInstance] joinLobby];
}

-(IBAction)chatButtonAction:(id)sender
{
    [[WarpClient getInstance] sendChat:@"Hi"];
}

-(IBAction)subscribeRoomButtonAction:(id)sender
{
    [[WarpClient getInstance] subscribeRoom:roomId];
}

-(IBAction)subscribeLobbyButtonAction:(id)sender
{
    [[WarpClient getInstance] subscribeLobby];
}

-(IBAction)updatePeersButtonAction:(id)sender
{
    NSDictionary *dataDict = [NSDictionary dictionaryWithObjectsAndKeys:nameTextField.text,@"userName",roomNameTextField.text,@"roomName",@"Hello there !",@"message", nil];
    
    
    if(!dataDict)
		return;
    
	NSError *error = nil;
	//converting the content to plist supported binary format.
	NSData *convertedData = [NSPropertyListSerialization dataWithPropertyList:dataDict format:NSPropertyListXMLFormat_v1_0 options:0 error:&error];
	
	if(error || ! convertedData)
	{
		NSLog(@"DataConversion Failed.ErrorDescription: %@",[error description]);
		return;
	}
    NSLog(@"%s",__FUNCTION__);
    [[WarpClient getInstance] sendUpdatePeers:convertedData];
}

-(IBAction)getAllRoomsButtonAction:(id)sender
{
    [[WarpClient getInstance] getAllRooms];
}

- (IBAction)getLiveRoomInfo:(id)sender {
    [[WarpClient getInstance] getLiveRoomInfo:roomId];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}


@end
