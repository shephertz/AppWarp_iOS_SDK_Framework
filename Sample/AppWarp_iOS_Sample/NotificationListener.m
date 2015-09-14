//
//  NotificationListener.m
//  AppWarp_Project
//
//  Created by Shephertz Technology on 06/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import "NotificationListener.h"

@implementation NotificationListener

@synthesize helper;

-(id)initWithHelper:(id)l_helper
{
    if (self=[super init])
    {
        self.helper = l_helper;
    }
    return self;
}
-(void)dealloc
{
    if (self.helper)
    {
        self.helper = nil;
    }
    [super dealloc];
}


-(void)onRoomCreated:(RoomData*)roomEvent
{
    NSLog(@"%s",__func__);
}

-(void)onRoomDestroyed:(RoomData*)roomEvent
{
    NSLog(@"%s",__func__);
}

-(void)onUserLeftRoom:(RoomData*)roomData username:(NSString*)username
{
    NSLog(@"%s..UserName=%@",__func__,username);
}

-(void)onUserJoinedRoom:(RoomData*)roomData username:(NSString*)username
{
    NSLog(@"%s..UserName=%@",__func__,username);
}

-(void)onUserLeftLobby:(LobbyData*)lobbyData username:(NSString*)username
{
    NSLog(@"%s..UserName=%@",__func__,username);
}

-(void)onUserJoinedLobby:(LobbyData*)lobbyData username:(NSString*)username
{
    NSLog(@"%s..UserName=%@",__func__,username);
}

-(void)onChatReceived:(ChatEvent*)chatEvent
{
    NSLog(@"%s",__func__);
    NSLog(@"Sender: %@",chatEvent.sender);
    NSLog(@"Message: %@",chatEvent.message);
}

-(void)onUpdatePeersReceived:(UpdateEvent*)updateEvent
{
    NSLog(@"%s",__FUNCTION__);
    NSData *data = updateEvent.update;
    NSError *error = nil;
	NSPropertyListFormat plistFormat;
    //converting the data into plist supported object.
	if(!data)
	{
		return;
	}
	
	id contentObject = [NSPropertyListSerialization propertyListWithData:data options:0 format:&plistFormat error:&error];
	
	if(error)
	{
		NSLog(@"DataConversion Failed. ErrorDescription: %@",[error description]);
		return;
	}
    NSLog(@"Data received--- %@",contentObject);
}


-(void)onMoveCompleted:(MoveEvent *)moveEvent
{
    NSLog(@"%s",__func__);
}

-(void)onUserChangeRoomProperty:(RoomData *)event username:(NSString *)username properties:(NSDictionary *)properties lockedProperties:(NSDictionary *)lockedProperties
{
    NSLog(@"%s...properties=%@",__FUNCTION__,properties);
    
    NSLog(@"Type=%@",[properties class]);
}

-(void)onUserResumed:(NSString *)userName withLocation:(NSString *)locId isLobby:(BOOL)isLobby
{
    NSLog(@"%s..UserName=%@",__func__,userName);
}

-(void)onUserPaused:(NSString *)userName withLocation:(NSString *)locId isLobby:(BOOL)isLobby
{
    NSLog(@"%s..UserName=%@",__func__,userName);
}

-(void)onGameStarted:(NSString *)sender roomId:(NSString *)roomId nextTurn:(NSString *)nextTurn
{
    NSLog(@"%s",__func__);
}
-(void)onGameStopped:(NSString *)sender roomId:(NSString *)roomId
{
    NSLog(@"%s",__func__);
}

-(void)onPrivateChatReceived:(NSString *)message fromUser:(NSString *)senderName
{
    NSLog(@"%s",__func__);
}


@end
