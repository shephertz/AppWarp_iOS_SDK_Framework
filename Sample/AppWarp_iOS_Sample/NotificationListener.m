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
    
}

-(void)onRoomDestroyed:(RoomData*)roomEvent
{
    
}

-(void)onUserLeftRoom:(RoomData*)roomData username:(NSString*)username
{
    
}

-(void)onUserJoinedRoom:(RoomData*)roomData username:(NSString*)username
{
    
}

-(void)onUserLeftLobby:(LobbyData*)lobbyData username:(NSString*)username
{
    
}

-(void)onUserJoinedLobby:(LobbyData*)lobbyData username:(NSString*)username
{
    
}

-(void)onChatReceived:(ChatEvent*)chatEvent
{
    
        
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

-(void)onUserChangeRoomProperty:(RoomData *)event username:(NSString *)username properties:(NSDictionary *)properties
{
    
}


@end
