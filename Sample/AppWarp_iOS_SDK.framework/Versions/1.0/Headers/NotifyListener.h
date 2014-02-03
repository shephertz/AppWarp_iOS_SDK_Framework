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
#import "MoveEvent.h"

@protocol NotifyListener <NSObject>
@required
/**
 * Invoked when a room is created. Lobby subscribers will receive this.
 * @param event
 */
-(void)onRoomCreated:(RoomData*)roomData;
/**
 * Invoked when a room is deleted. Lobby subscribers will receive this.
 * @param event
 */
-(void)onRoomDestroyed:(RoomData*)roomData;
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
 * Invoked when a joined user sends a chat. Rooms subscribers will receive this.
 * @param event
 */
-(void)onPrivateChatReceived:(NSString*)message fromUser:(NSString*)senderName;

/**
 * Invoked when a joined user sends a updatePeers request. Rooms subscribers 
 * will receive this.
 * @param event
 */
-(void)onUpdatePeersReceived:(UpdateEvent*)updateEvent;
/**
 * Invoked when a user change room property. Lobby and the concerned room subscribers
 * will receive this.
 * @param event
 * @param username
 * @param properties
 * @param lockedProperties
 */
-(void)onUserChangeRoomProperty:(RoomData*)event username:(NSString*)username properties:(NSDictionary*)properties lockedProperties:(NSDictionary*)lockedProperties;

/*
 * Invoked when a user's move is completed in a turn based room
 */
-(void)onMoveCompleted:(MoveEvent*) moveEvent;


/**
 * Invoked to indicate that a user has lost connectivity. Subscribers of the users location
 * will receive this.
 * @param locid
 * @param isLobby
 * @param username
 */
-(void)onUserPaused:(NSString*)userName withLocation:(NSString*)locId isLobby:(BOOL)isLobby;

/**
 * Invoked when a user's connectivity is restored. Subscribers of the users location
 * will receive this.
 * @param locid
 * @param isLobby
 * @param username
 */
-(void)onUserResumed:(NSString*)userName withLocation:(NSString*)locId isLobby:(BOOL)isLobby;

/*
 * Invoked when a user starts game in a turn based room
 */
-(void)onGameStarted:(NSString*)sender roomId:(NSString*)roomId  nextTurn:(NSString*)nextTurn;

/*
 * Invoked when a user stops game in a turn based room
 */
-(void)onGameStopped:(NSString*)sender roomId:(NSString*)roomId;

@end