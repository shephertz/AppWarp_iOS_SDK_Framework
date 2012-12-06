//
//  RoomListener.m
//  AppWarp_Project
//
//  Created by Shephertz Technology on 06/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import "RoomListener.h"

@implementation RoomListener

@synthesize viewControllerObject;

-(id)initWithViewController:(TestClassViewController*)controller{
    self.viewControllerObject = controller;
    return self;
}

-(void)onSubscribeRoomDone:(RoomEvent*)roomEvent{
    
    if (roomEvent.result == SUCCESS) {
        [self.viewControllerObject updateResultLabel:@"Subscribed"];
        [[WarpClient getInstance]setCustomRoomData:roomEvent.roomData.roomId roomData:@"custom room data set"];
    }
    else {
        [self.viewControllerObject updateResultLabel:@"subscribed failed"];
    }
}
-(void)onUnSubscribeRoomDone:(RoomEvent*)roomEvent{
    if (roomEvent.result == SUCCESS) {
        [self.viewControllerObject updateResultLabel:@"Room Unsubscribed"];
        [[WarpClient getInstance]deleteRoom:roomEvent.roomData.roomId];
    }
    else {
        [self.viewControllerObject updateResultLabel:@"Room Unsubscribed failed"];
    }
}
-(void)onJoinRoomDone:(RoomEvent*)roomEvent{
//    NSLog(@"on Join room listener called");
    
    if (roomEvent.result == SUCCESS) {
        [self.viewControllerObject updateResultLabel:@"Room Joined"];
        RoomData *roomData = roomEvent.roomData;
        [[WarpClient getInstance]subscribeRoom:roomData.roomId];
        self.viewControllerObject.roomId = roomData.roomId;
    }
    else {
        [self.viewControllerObject updateResultLabel:@"Room Join failed"];
    }
    
}
-(void)onLeaveRoomDone:(RoomEvent*)roomEvent{
    if (roomEvent.result == SUCCESS) {
        [self.viewControllerObject updateResultLabel:@"Room Left"];
        [[WarpClient getInstance]unsubscribeRoom:roomEvent.roomData.roomId];
    }
    else {
        [self.viewControllerObject updateResultLabel:@"Room Left failed"];
    }
}
-(void)onGetLiveRoomInfoDone:(LiveRoomInfoEvent*)event{
    NSString *joinedUsers = [NSString stringWithString:@""];
    NSLog(@"joined users array = %@",event.joinedUsers);
    
    for (int i=0; i<[event.joinedUsers count]; i++) {
        joinedUsers = [joinedUsers stringByAppendingString:[event.joinedUsers objectAtIndex:i]];
    }
    
    [self.viewControllerObject updateResultLabel:joinedUsers];
    
    
}
-(void)onSetCustomRoomDataDone:(LiveRoomInfoEvent*)event{
    NSLog(@"event joined users = %@",event.joinedUsers);
    NSLog(@"event custom data = %@",event.customData);
    [self.viewControllerObject updateResultLabel:event.customData];

}

@end
