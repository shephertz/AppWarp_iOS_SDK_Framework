//
//  ZoneListener.m
//  AppWarp_iOS_Sample
//
//  Created by shephertz technologies on 22/05/13.
//  Copyright (c) 2013 shephertz technologies. All rights reserved.
//

#import "ZoneListener.h"
#import "ViewController.h"
@implementation ZoneListener

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


-(void)onCreateRoomDone:(RoomEvent*)roomEvent
{
    
    if (roomEvent.result == SUCCESS)
    {
        RoomData *roomData = roomEvent.roomData;
        NSLog(@"roomEvent result = %i",roomEvent.result);
        NSLog(@"room id = %@",roomData.roomId);
        [helper setRoomId:roomData.roomId];
        //[[WarpClient getInstance] joinRoom:roomData.roomId];
        [helper updateResponseLabel:[NSString stringWithFormat:@"Success....roomId=%@",roomData.roomId]];
    }
    else
    {
        [helper updateResponseLabel:[NSString stringWithFormat:@"Create room Failed with error code = %d",roomEvent.result]];
    }
    
}

-(void)onDeleteRoomDone:(RoomEvent*)roomEvent
{
    if (roomEvent.result == SUCCESS)
    {
        
    }
    else
    {
        
    }
}

-(void)onGetAllRoomsDone:(AllRoomsEvent*)event
{
    NSLog(@"%s Result=%d",__FUNCTION__,event.result);
    if (event.result == SUCCESS)
    {
        NSLog(@"%s Rooms=%@",__FUNCTION__,event.roomIds);
        
    }
    else
    {
        
    }
}
-(void)onGetOnlineUsersDone:(AllUsersEvent*)event
{
    if (event.result == SUCCESS)
    {
        NSLog(@"usernames = %@",event.userNames);
    }
    else
    {
        
    }
    
}

-(void)onGetLiveUserInfoDone:(LiveUserInfoEvent*)event
{
    NSLog(@"onGetLiveUserInfo called");
    if (event.result == SUCCESS)
    {
        
    }
    else
    {
        
    }
    
}

-(void)onSetCustomUserDataDone:(LiveUserInfoEvent*)event
{
    if (event.result == SUCCESS)
    {
        
    }
    else
    {
        
    }
}

-(void)onGetMatchedRoomsDone:(MatchedRoomsEvent*)event
{
    if (event.result == SUCCESS)
    {
        
    }
    else
    {
        
    }
}

@end
