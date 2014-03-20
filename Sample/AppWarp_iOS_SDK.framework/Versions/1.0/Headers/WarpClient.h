//
//  WarpClient.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 27/07/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ClientChannel.h"
#import "WarpResponse.h"
#import "WarpNotifyMessage.h"

@interface WarpClient : NSObject<NSURLConnectionDelegate>{
    
}

@property(nonatomic,retain)ClientChannel *clientChannelRef;
@property(nonatomic,retain)NSString *apiKey;
@property(nonatomic,retain)NSString *secretKey;
@property(nonatomic,retain)NSString *userName;
//@property(nonatomic,retain)NSString *warpServerHost;


/**
 * Gives the singleton instance of WarpClient (if initialized with keys).
 * If not initialized, this will throw an Exception
 * @return WarpClient
 */
+(WarpClient*)getInstance;

/**
 * This should be your first API call to WarpClient. This will instantiate
 * the WarpClient singleton and set it up to be used with the keys provided 
 * in params. Calling it more than once will return error.
 * @param apiKey
 * @param pvtKey
 * @return 
 */
+(BOOL)initWarp:(NSString*)apiKey secretKey:(NSString*)secretKey;
/**
 * This should be your first API call to WarpClient. This will instantiate
 * the WarpClient singleton and set it up to be used with the keys provided
 * in params. Calling it more than once will return error.
 * @param apiKey
 * @param pvtKey
 * @return
 */
+(BOOL)initWarp:(NSString*)apiKey secretKey:(NSString*)secretKey hostAddress:(NSString*)hostAddress;

/**
 *This API checks if device has a full duplex UDP connection or not with the AppWarp server. 
 *Incoming UDP Traffic may be blocked if the client is behind certain types of NATs(Network address translation). 
 *It determines the connectivity by performing a 3-way handshake with the server over UDP and provides 
 *the result in onInitUDPDone callbacks of the ConnectionRequestListener. 
 *In case of lack of connectivity, the server will fall back to sending updates over TCP for the client. 
 *Sending can continue over UDP irrespective.
 **/
-(void)initUDP;

/**
 * Sends connection as well as authentication request to the WARP server 
 * with the given username string. The result of the operation
 * is provided in the onConnectDone callback of the ConnectionListener.
 * @param user
 */
-(void)connectWithUserName:(NSString*)userName;

/**
 * Disconnects the connection with the WARP server. The result for
 * this request will be provided in the onDisconnectDone callback of the
 * ConnectionListener.
 */
-(void)disconnect;
/**
 * Gives the current connection state of the client as
 * com.shephertz.app42.gaming.multiplayer.client.ConnectionState
 * @return
 */
-(int)getConnectionState;
-(void)onResponse:(WarpResponse*)response;
-(void)onNotify:(WarpNotifyMessage*)notify;
-(void)onConnect:(BOOL)value;
-(void)fireUDPEvent:(Byte)resultCode;
/**
 * sends a unsubscribe lobby request to the server. Result of the request is provided
 * in the onUnSubscribeLobbyDone callback of the LobbyListener.
 * @param name
 * @param owner
 * @param properties
 * @param maxUsers
 */
-(void)createRoomWithRoomName:(NSString*)roomName roomOwner:(NSString*)roomOwner properties:(NSDictionary*)properties maxUsers:(int)maxUsers;

/**
 * sends a create turn based room request to the server. Result of the request is
 * provided in the onCreateRoomDone callback of the ZoneRequestListener.
 *
 * @param name
 * @param owner
 * @param maxUsers
 * @param time
 */
-(void)createTurnRoomWithRoomName:(NSString*)roomName roomOwner:(NSString*)roomOwner properties:(NSDictionary*)properties maxUsers:(int)maxUsers turnExpiresIn:(int)time;

/**
 * Sends a update room properties request to the server. Result of the request is provided
 * in the onUpdatePropertyDone callback of the LobbyListener.
 * @param name
 * @param owner
 * @param properties
 * @param maxUsers
 */

-(void)updateRoom:(NSString *)roomID  addProperties:(NSDictionary*)propertiesDict removeProperties:(NSArray*)propertiesKeyArray;
/**
 * sends a delete room request to the server. Result of the request is provided
 * in the onDeleteRoomDone callback of the ZoneListener.
 * @param roomId
 */
-(void)deleteRoom:(NSString*)roomId;
/**
 * Updates the custom data associated with the given room on the server. Result is
 * provided in the onSetCustomRoomDataDone callback of the RoomListener.
 * @param roomId
 * @param customData
 */
-(void)setCustomRoomData:(NSString*)roomId customData:(NSString*)customData;
/**
 * Updates the custom data associated with the given user on the server. Result is
 * provided in the onSetCustomUserDataDone callback of the ZoneListener.
 * @param username
 * @param customData
 */
-(void)setCustomUserData:(NSString*)username customData:(NSString*)customData;
/**
 * Retrieves usernames of all the users connected to the server. Result is
 * provided in the onGetOnlineUsersDone callback of the ZoneListener.
 */
-(void)getOnlineUsers;
/**
 * Retrieves room ids of all the live rooms on the server. Result is
 * provided in the onGetAllRoomsDone callback of the ZoneListener.
 */
-(void)getAllRooms;
/**
 * Retrieves information of the room that contain specific
 * properties from the server. Result is
 * provided in the onGetMatchedRoomsDone callback of the ZoneListener.
 * @param roomid
 */
-(void)getRoomWithProperties:(NSDictionary*) properties;

/**
 * Retrieves live information of the user from the server. Result is
 * provided in the onGetLiveUserInfoDone callback of the ZoneListener.
 * @param username
 */
-(void)getLiveUserInfo:(NSString*)username;
/**
 * Retrieves live information of the room from the server. Result is
 * provided in the onGetLiveRoomInfo callback of the RoomListener.
 * @param roomId
 */
-(void)getLiveRoomInfo:(NSString*)roomId;
/**
 * Retrieves live information of the lobby from the server. Result is
 * provided in the onGetLiveLobbyInfo callback of the LobbyListener.
 */
-(void)getLiveLobbyInfo;
/**
 * sends a join lobby request to the server. Result of the request is provided
 * in the onJoinLobbyDone callback of the LobbyListener
 */ 
-(void)joinLobby;
/**
 * sends a leave lobby request to the server. Result of the request is provided
 * in the onLeaveLobbyDone callback of the LobbyListener
 */
-(void)leaveLobby;
/**
 * sends a subscribe lobby request to the server. Result of the request is provided
 * in the onSubscribeLobbyDone callback of the LobbyListener
 */
-(void)subscribeLobby;
/**
 * sends a unsubscribe lobby request to the server. Result of the request is provided
 * in the onUnSubscribeLobbyDone callback of the LobbyListener
 */
-(void)unsubscribeLobby;
/**
 * sends a join room request to the server. Result of the request is provided
 * in the onJoinRoomDone callback of the RoomListener.
 * @param roomId
 */
-(void)joinRoom:(NSString*)roomId;
/**
 * Sends a join room request to the server with the condition that the room must have
 * a matching set of property value pairs associated with it. This is useful in match making.
 * Result of the request is provided in the onJoinRoomDone callback of the registered RoomRequestListener.
 * @param properties
 */
-(void)joinRoomWithProperties:(NSDictionary*)properties;
/**
 * sends a leave room request to the server. Result of the request is provided
 * in the onLeaveRoomDone callback of the RoomListener.
 * @param roomId
 */
-(void)leaveRoom:(NSString*)roomId;
/**
 * sends a subscribe room request to the server. Result of the request is provided
 * in the onSubscribeRoomDone callback of the RoomListener.
 * @param roomId
 */
-(void)subscribeRoom:(NSString*)roomId;
/**
 * sends a unsubscribe room request to the server. Result of the request is provided
 * in the onUnsubscribeRoomDone callback of the RoomListener.
 * @param roomId
 */
-(void)unsubscribeRoom:(NSString*)roomId;

/**
 * sends a private message to user it it does not matter user is in which room.
 * Result of the request is provided in the onSendChatDone callback of the
 * ChatListener.
 *
 * @param message 
 * @param userName
 */

-(void)sendPrivateChat:(NSString*)message toUser:(NSString*)userName;

/**
 * sends a chat message to room in which the user is currently joined. Result of 
 * the request is provided in the onSendChatDone callback of the ChatListener.
 * @param message
 */
-(void)sendChat:(NSString*)message;
/**
 * sends a custom update message to room in which the user is currently joined. Result of 
 * the request is provided in the onSendUpdatePeersDone callback of the UpdateListener.
 * @param update
 */

-(void)sendUpdatePeers:(NSData*)update;

/**
 * sends a custom update message to room in which the user is currently joined. The 
 * update is sent using UDP protocol and is unreliable.
 * @param update
 */

-(void)sendUdpUpdatePeers:(NSData*)update;

/**
 * add your listener object on which callbacks will be invoked when
 * a response from the server is received for connect, authenticate and
 * disconnect APIs.
 * @param listener
 */
-(void)addConnectionRequestListener:(id)conListener;
/**
 * add your listener object on which callbacks will be invoked when
 * a response from the server is received for Zone level requests like
 * create/deleteRoom, User requests etc.      
 * disconnect APIs.
 * @param listener
 */
-(void)addZoneRequestListener:(id)zoneListener;
/**
 * add your listener object on which callbacks will be invoked when
 * a response from the server is received for Lobby requests like
 * join/leaveLobby, subscribe/unsubscribeLobby and getLiveLobbyInfo
 * @param listener
 */
-(void)addLobbyRequestListener:(id)lobbyListener;
/**
 * add your listener object on which callbacks will be invoked when
 * a response from the server is received for sendChat request.
 * 
 * @param listener
 */
-(void)addChatRequestListener:(id)chatListener;
/**
 * add your listener object on which callbacks will be invoked when
 * a response from the server is received for sendUpdate request.
 * @param listener
 */
-(void)addUpdateRequestListener:(id)updateListener;
/**
 * add your listener object on which callbacks will be invoked when
 * a response from the server is received for Room requests like
 * join/leaveRoom, subscribe/unsubscribeRoom and getLiveRoomInfo
 * @param listener
 */
-(void)addRoomRequestListener:(id)roomListener;
/**
 * add your listener object on which callbacks will be invoked when
 * a notification is received from the server for any resource that has
 * been subscribed to.
 * @param listener
 */
-(void)addNotificationListener:(id)notifyListener;

/**
 * add your listener object on which callbacks will be invoked when
 * a response from the server is received for Turn Based Room requests like
 * join/leaveRoom, subscribe/unsubscribeRoom and getLiveRoomInfo
 * @param turnBasedRoomListener
 */
-(void)addTurnBasedRoomListener:(id)turnBasedRoomListener;

/**
 * remove your listener for connection requests
 * @param conListener
 */
-(void)removeConnectionRequestListener:(id)conListener;
/**
 * Remove your listener for zone requests
 * @param zoneListener
 */
-(void)removeZoneRequestListener:(id)zoneListener;
/**
 * Remove your listener for lobby requests
 * @param lobbyListener
 */
-(void)removeLobbyRequestListener:(id)lobbyListener;
/**
 * Remove your listener for send chat requests
 * @param chatListener
 */
-(void)removeChatRequestListener:(id)chatListener;

/**
 * Remove your listener for update requests
 * @param updateListener
 */
-(void)removeUpdateRequestListener:(id)updateListener;
/**
 * Remove your listener for rooms requests
 * @param roomListener
 */
-(void)removeRoomRequestListener:(id)roomListener;
/**
 * Remove your listener for notifications
 * @param notifyListener
 */
-(void)removeNotificationListener:(id)notifyListener;

/**
 * Remove your listener for turnBasedRoom
 * @param turnBasedRoomListener
 */
-(void)removeTurnBasedRoomListener:(id)turnBasedRoomListener;

/**
 * Lock the properties associated with the joined room on the server for requested user.
 * Result is provided in the onLockPropertyDone callback of the registered
 * RoomRequestListener objects. Lock properties will fail if any other user has lock on same
 * property, otherwise property will be added in lockTable with owner name. This request
 * (if successful) will also result in an onUserChangeRoomProperty notification on the
 * registered NotifyListener objects to be triggered for all subscribed users of the room.
 *
 * @param properties
 */
-(void)lockRoomProperties:(NSDictionary*)roomProperties;

/**
 * Unlock the properties associated with the joined room on the server for requested user.
 * Result is provided in the onUnlockPropertyDone callback of the registered
 * RoomRequestListener objects. Unlock properties will fail if any other user has lock on
 * same property, otherwise property will be removed from lock table. This request
 * (if successful) will also result in an onUserChangeRoomProperty notification on the
 * registered NotifyListener objects to be triggered for all subscribed users of the room.
 *
 * @param properties
 */
-(void)unlockRoomProperties:(NSArray*) unlockPropertiesKeyArray;

/**
 * send a join room request to server with matchmaking parameters this method
 * allow user to choose room with user to specified range and also a flag
 * which decide priority to room
 * Result of the request is provided in the onJoinRoomDone callback of the RoomListener.
 *
 * @param minUser: number of minimum user in the room
 * @param maxUser: number if maximum user in the room
 * @param maxPreferred: define search priority
 */
-(void)joinRoomInRangeBetweenMinUsers:(int)minUsers andMaxUsers:(int)maxUsers maxPrefered:(BOOL)maxPrefered;

/**
 * Retrieves information of the room that contain user in given range it from the server. Result is
 * provided in the onGetLiveRoomInfo callback of the RoomListener.
 * @param minUser, maxUser
 * not in used because of server site bug
 */
-(void)getRoomsInRangeBetweenMinUser:(int)minUsers andMaxUser:(int)maxUsers;

/*
 * Sends a move to the joined turn based room. Only allowed if its the sender's
 * turn.
 */
-(void) sendMove:(NSString*) moveData;

/*
 * Sets the connection recovery time (seconds) allowed that will be negotiated
 * with the server. By default it is 0 so there is no connection recovery.
 */
-(void)setRecoveryAllowance:(int) maxRecoveryTime;


/* Attempts to reconnect and recover the session. May succeed if done within
 * the reconnect time limit negotiated during start up.
 */
-(void)recoverConnection;

/*
 * Enable or Disable trace to system.out. Default is disabled.
 */
-(void)enableTrace:(BOOL)isEnable;

/**
 * sends a start game request to the server. Result of the request is
 * provided in the onGameStarted callback of the TurnBasedRoomListener.
 *
 */
-(void)startGame;

/**
 * sends a stop game request to the server. Result of the request is
 * provided in the onGameStopped callback of the TurnBasedRoomListener.
 *
 */
-(void)stopGame;

/**
 * sends a get move history request to the server. Result of the request is
 * provided in the onGetMoveHistoryDone callback of the TurnBasedRoomListener.
 */
-(void)getMoveHistory;


-(void)setGeo:(NSString*)_geo;
-(void)setServer:(NSString*)server;

@end
