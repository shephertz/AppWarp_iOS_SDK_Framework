//
//  NotifyListener.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 03/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RoomData.h"
#import "LobbyData.h"
#import "ChatEvent.h"
#import "UpdateEvent.h"

@protocol NotifyListener <NSObject>
@required
/**
 * Invoked when a room is created. Lobby subscribers will receive this.
 * @param event
 */
-(void)onRoomCreated:(RoomData*)roomEvent;
/**
 * Invoked when a room is deleted. Lobby subscribers will receive this.
 * @param event
 */
-(void)onRoomDestroyed:(RoomData*)roomEvent;
/**
 * Invoked when a user leaves a room. Lobby and the concerned room subscribers 
 * will receive this.
 * @param event
 * @param username
 */
-(void)onUserLeftRoom:(RoomData*)roomData username:(NSString*)username;
/**
 * Invoked when a user joins a room. Lobby and the concerned room subscribers 
 * will receive this.
 * @param event
 * @param username
 */
-(void)onUserJoinedRoom:(RoomData*)roomData username:(NSString*)username;
/**
 * Invoked when a user leaves a lobby. Lobby subscribers will receive this.
 * @param event
 * @param username
 */
-(void)onUserLeftLobby:(LobbyData*)lobbyData username:(NSString*)username;
/**
 * Invoked when a user joins a lobby. Lobby subscribers will receive this.
 * @param event
 * @param username
 */
-(void)onUserJoinedLobby:(LobbyData*)lobbyData username:(NSString*)username;
/**
 * Invoked when a joined user sends a chat. Rooms subscribers will receive this.
 * @param event
 */
-(void)onChatReceived:(ChatEvent*)chatEvent;
/**
 * Invoked when a joined user sends a updatePeers request. Rooms subscribers 
 * will receive this.
 * @param event
 */
-(void)onUpdatePeersReceived:(UpdateEvent*)updateEvent;

@end