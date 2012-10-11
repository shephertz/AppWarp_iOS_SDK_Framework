//
//  LobbyRequestListener.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 03/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LobbyEvent.h"
#import "LiveRoomInfoEvent.h"

@protocol LobbyRequestListener <NSObject>

@required
/**
 * Invoked in response to a joinLobby request.
 * @param event
 */
-(void)onJoinLobbyDone:(LobbyEvent*)lobbyEvent;
/**
 * Invoked in response to a leaveLobby request.
 * @param event
 */
-(void)onLeaveLobbyDone:(LobbyEvent*)lobbyEvent;
/**
 * Invoked in response to a subscribeLobby request.
 * @param event
 */
-(void)onSubscribeLobbyDone:(LobbyEvent*)lobbyEvent;
/**
 * Invoked in response to a UnSubscribeLobby request.
 * @param event
 */
-(void)onUnSubscribeLobbyDone:(LobbyEvent*)lobbyEvent;
/**
 * Invoked in response to a getLiveLobbyInfo request.
 * @param event
 */
-(void)onGetLiveLobbyInfoDone:(LiveRoomInfoEvent*)event;

@end
