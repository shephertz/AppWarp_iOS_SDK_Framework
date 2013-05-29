//
//  LobbyListener.m
//  AppWarp_iOS_Sample
//
//  Created by shephertz technologies on 23/05/13.
//  Copyright (c) 2013 shephertz technologies. All rights reserved.
//

#import "LobbyListener.h"
#import "ViewController.h"

@implementation LobbyListener
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


-(void)onJoinLobbyDone:(LobbyEvent*)lobbyEvent
{
    NSLog(@"%s",__FUNCTION__);
    if (lobbyEvent.result == SUCCESS)
    {
        [helper updateResponseLabel:@"Joined Lobby"];
        
    }
    else
    {
        [helper updateResponseLabel:[NSString stringWithFormat:@"Error Code = %d",lobbyEvent.result]];
    }

}
-(void)onLeaveLobbyDone:(LobbyEvent*)lobbyEvent
{
    
}
-(void)onSubscribeLobbyDone:(LobbyEvent*)lobbyEvent
{
    if (lobbyEvent.result == SUCCESS)
    {
        [helper updateResponseLabel:@"Subscribed Lobby"];
        
    }
    else
    {
        [helper updateResponseLabel:[NSString stringWithFormat:@"Error Code = %d",lobbyEvent.result]];
    }
}
-(void)onUnSubscribeLobbyDone:(LobbyEvent*)lobbyEvent
{
    
}
-(void)onGetLiveLobbyInfoDone:(LiveRoomInfoEvent*)event
{
    
}
@end
