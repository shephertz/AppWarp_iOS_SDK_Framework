//
//  NotificationListener.m
//  AppWarp_Project
//
//  Created by Shephertz Technology on 06/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import "NotificationListener.h"

@implementation NotificationListener

@synthesize viewControllerObject;

-(id)initWithViewController:(TestClassViewController*)controller{
    self.viewControllerObject = controller;
    return self;
}

-(void)onRoomCreated:(RoomData*)roomEvent{
    
}
-(void)onRoomDestroyed:(RoomData*)roomEvent{
    
}
-(void)onUserLeftRoom:(RoomData*)roomData username:(NSString*)username{
    
}
-(void)onUserJoinedRoom:(RoomData*)roomData username:(NSString*)username{
    
}
-(void)onUserLeftLobby:(LobbyData*)lobbyData username:(NSString*)username{
    
}
-(void)onUserJoinedLobby:(LobbyData*)lobbyData username:(NSString*)username{
    
}
-(void)onChatReceived:(ChatEvent*)chatEvent{
    [self.viewControllerObject updateResultLabel:[NSString stringWithFormat:@"%@  %@",chatEvent.sender,chatEvent.message]];
    
    //[[WarpClient getInstance]leaveRoom:chatEvent.locId];
    //[[WarpClient getInstance]leaveLobby];
    
}
-(void)onUpdatePeersReceived:(UpdateEvent*)updateEvent{
    NSString *updatePeersString = [[NSString alloc] initWithData:updateEvent.update encoding:NSUTF8StringEncoding];
    [self.viewControllerObject updateResultLabel:[NSString stringWithFormat:@"%@",updatePeersString]];
    [[WarpClient getInstance]leaveLobby];
}

@end
