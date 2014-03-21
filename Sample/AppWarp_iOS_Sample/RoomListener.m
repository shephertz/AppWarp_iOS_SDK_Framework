//
//  RoomListener.m
//  AppWarp_Project
//
//  Created by Shephertz Technology on 06/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import "RoomListener.h"
#import "ViewController.h"

@implementation RoomListener

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


-(void)onSubscribeRoomDone:(RoomEvent*)roomEvent
{
    
    if (roomEvent.result == SUCCESS)
    {
        RoomData *roomData = roomEvent.roomData;
        [helper updateResponseLabel:[NSString stringWithFormat:@"Subscribed Room with roomId = %@",roomData.roomId]];
        NSLog(@"onSubscribeRoomDone  SUCCESS");
    }
    else
    {
        NSLog(@"onSubscribeRoomDone  Failed");
    }
}

-(void)onUnSubscribeRoomDone:(RoomEvent*)roomEvent
{
    if (roomEvent.result == SUCCESS)
    {
        
    }
    else
    {
        
    }
}

-(void)onJoinRoomDone:(RoomEvent*)roomEvent
{
   NSLog(@".onJoinRoomDone..on Join room listener called");
    
    if (roomEvent.result == SUCCESS)
    {
        RoomData *roomData = roomEvent.roomData;
        [helper updateResponseLabel:[NSString stringWithFormat:@"Joined Room with roomId = %@",roomData.roomId]];
        
        NSLog(@".onJoinRoomDone..on Join room listener called Success");
    }
    else
    {
        [helper updateResponseLabel:[NSString stringWithFormat:@"Error Code = %d",roomEvent.result]];
        NSLog(@".onJoinRoomDone..on Join room listener called failed");
    }
}

-(void)onLeaveRoomDone:(RoomEvent*)roomEvent
{
    if (roomEvent.result == SUCCESS)
    {
        
    }
    else
    {
        
    }
}

-(void)onGetLiveRoomInfoDone:(LiveRoomInfoEvent*)event
{
    NSString *joinedUsers = @"";
    NSLog(@"joined users array = %@",event.joinedUsers);
    NSLog(@"Got live info for room id %@", event.roomData.roomId);
    NSLog(@"joined users=%@",event.joinedUsers);
    NSLog(@"properties = %@",event.properties);
    NSLog(@"lockPropeties = %@",event.lockPropeties);
    NSLog(@"customData = %@",event.customData);

    for (int i=0; i<[event.joinedUsers count]; i++)
    {
        joinedUsers = [joinedUsers stringByAppendingString:[event.joinedUsers objectAtIndex:i]];
    }
}

-(void)onSetCustomRoomDataDone:(LiveRoomInfoEvent*)event
{
    NSLog(@"event joined users = %@",event.joinedUsers);
    NSLog(@"event custom data = %@",event.customData);

}

-(void)onUpdatePropertyDone:(LiveRoomInfoEvent *)event
{
    if (event.result == SUCCESS)
    {
        //[[WarpClient getInstance]unsubscribeRoom:roomEvent.roomData.roomId];
    }
    else
    {
        
    }

}

@end
