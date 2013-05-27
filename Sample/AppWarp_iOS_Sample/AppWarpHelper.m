//
//  AppWarpHelper.m
//  AppWarp_iOS_Sample
//
//  Created by shephertz technologies on 22/05/13.
//  Copyright (c) 2013 shephertz technologies. All rights reserved.
//

#import "AppWarpHelper.h"
#import <AppWarp_iOS_SDK/AppWarp_iOS_SDK.h>
#import "ConnectionListener.h"
#import "RoomListener.h"
#import "NotificationListener.h"
#import "ZoneListener.h"
#import "LobbyListener.h"
#import "ChatListener.h"

#define APPWARP_APP_KEY     @"cad2bfab6310acd9696187b98682925125e469ab0d0d585db0b00609f461b791"
#define APPWARP_SECRET_KEY  @"55811709916e7ce4405cde0cdc5a254cf4b506fbafdae05760a73100b8080b67"

static AppWarpHelper *appWarpHelper;

@implementation AppWarpHelper

@synthesize delegate,roomId,userName,roomName,roomOwner,maxUser,properties;

+(AppWarpHelper *)sharedAppWarpHelper
{
	if(appWarpHelper == nil)
	{
		appWarpHelper = [[self alloc] init];
	}
	return appWarpHelper;
}

- (id) init
{
	self = [super init];
	if (self != nil)
    {
        self.delegate    = nil;
        self.userName    = nil;
		self.roomId      = nil;
        self.roomName    = nil;
        self.roomOwner   = nil;
        self.properties  = nil;
	}
	return self;
}

- (void)dealloc
{
    if (delegate)
    {
        self.delegate=nil;
    }
    if (roomId)
    {
        self.roomId=nil;
    }
    if (userName)
    {
        self.userName=nil;
    }
    if (roomName)
    {
        self.roomName=nil;
    }
    if (roomOwner)
    {
        self.roomOwner=nil;
    }
    if (properties)
    {
        self.properties=nil;
    }
    [super dealloc];
}



#pragma mark -------------

-(void)initializeAppWarp
{
    [WarpClient initWarp:APPWARP_APP_KEY secretKey:APPWARP_SECRET_KEY];
    //[WarpClient initWarp:APPWARP_APP_KEY secretKey:APPWARP_SECRET_KEY hostAddress:@"192.168.1.149"];
    
    
    WarpClient *warpClient = [WarpClient getInstance];
    
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



-(void)connectToWarp
{
    [[WarpClient getInstance] connectWithUserName:userName];
}

-(void)disconnectWarp
{
    
    [[WarpClient getInstance] unsubscribeRoom:roomId];
    [[WarpClient getInstance] leaveRoom:roomId];
    [[WarpClient getInstance] disconnect];
    
}

-(void)createRoom
{
    NSLog(@"roomName=%@,roomOwner=%@,properties=%@,maxUser=%d",roomName,roomOwner,properties,maxUser);
    [[WarpClient getInstance] createRoomWithRoomName:roomName roomOwner:roomOwner properties:properties maxUsers:maxUser];
}

-(void)joinRoom
{
    NSLog(@"roomId=%@",roomId);
    [[WarpClient getInstance] joinRoom:roomId];
}

-(void)subscribeRoom
{
    [[WarpClient getInstance] subscribeRoom:roomId];
}
-(void)subscribeLobby
{
    [[WarpClient getInstance] subscribeLobby];
}

-(void)joinLobby
{
    [[WarpClient getInstance] joinLobby];
}

-(void)sendChat:(NSString*)message
{
    [[WarpClient getInstance] sendChat:message];
}

-(void)updatePeers:(NSDictionary *)dataDict
{
    NSLog(@"%s",__FUNCTION__);
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


-(void)getAllRooms
{
    [[WarpClient getInstance] getAllRooms];
}

@end
