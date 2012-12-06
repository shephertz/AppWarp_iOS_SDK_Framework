//
//  LobbyListener.m
//  AppWarp_Project
//
//  Created by Shephertz Technology on 06/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import "LobbyListener.h"

@implementation LobbyListener

@synthesize viewControllerObject;

-(id)initWithViewController:(TestClassViewController*)controller{
    self.viewControllerObject = controller;
    return self;
}

-(void)onJoinLobbyDone:(LobbyEvent*)lobbyEvent{
    if (lobbyEvent.result == SUCCESS) {
        [self.viewControllerObject updateResultLabel:@"Join lobby done"];
        [[WarpClient getInstance]subscribeLobby];
    }
    else {
        [self.viewControllerObject updateResultLabel:@"Join lobby failed"];
    }
}
-(void)onLeaveLobbyDone:(LobbyEvent*)lobbyEvent{
    if (lobbyEvent.result == SUCCESS) {
        [self.viewControllerObject updateResultLabel:@"Leave lobby done"];
        [[WarpClient getInstance]unsubscribeLobby];
    }
    else {
        [self.viewControllerObject updateResultLabel:@"Leave lobby failed"];
    }
}
-(void)onSubscribeLobbyDone:(LobbyEvent*)lobbyEvent{
    if (lobbyEvent.result == SUCCESS) {
        [self.viewControllerObject updateResultLabel:@"Subscribe lobby done. You can chat now"];
        //[[WarpClient getInstance]getLiveLobbyInfo];
    }
    else {
        [self.viewControllerObject updateResultLabel:@"Subscribe lobby failed"];
    }
}
-(void)onUnSubscribeLobbyDone:(LobbyEvent*)lobbyEvent{
    if (lobbyEvent.result == SUCCESS) {
        [self.viewControllerObject updateResultLabel:@"Unsubscribe lobby done"];
    }
    else {
        [self.viewControllerObject updateResultLabel:@"Unsubscribe lobby failed"];
    }
}
-(void)onGetLiveLobbyInfoDone:(LiveRoomInfoEvent*)event{
    NSString *joinedUsers = [NSString stringWithString:@""];
    NSLog(@"joined users array = %@",event.joinedUsers);
    
    for (int i=0; i<[event.joinedUsers count]; i++) {
        joinedUsers = [joinedUsers stringByAppendingString:[event.joinedUsers objectAtIndex:i]];
    }
    
    [self.viewControllerObject updateResultLabel:joinedUsers];
}


@end
