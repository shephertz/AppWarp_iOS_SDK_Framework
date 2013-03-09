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

@interface WarpClient : NSObject{
    
}

@property(nonatomic,retain)ClientChannel *clientChannelRef;
@property(nonatomic,retain)NSString *apiKey;
@property(nonatomic,retain)NSString *secretKey;



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
+(void)initWarp:(NSString*)apiKey secretKey:(NSString*)secretKey;
/**
 * sends an authentication request to the WARP server with the given
 * username string. This name must be unique amongst all users connected
 * to the server at a given moment. Result is provided in the onAuthenticationDone
 * callback of the ConnectionListener.
 * @param user
 */
-(void)joinZone:(NSString*)userName;
/**
 * Initiates your connection with the WARP server. The result of the operation
 * is provided in the onConnectDone callback of the ConnectionListener.
 */
-(void)connect;
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

/**
 * sends a unsubscribe lobby request to the server. Result of the request is provided
 * in the onUnSubscribeLobbyDone callback of the LobbyListener.
 * @param name
 * @param owner
 * @param maxUsers
 */
-(void)createRoomWithRoomName:(NSString*)roomName roomOwner:(NSString*)roomOwner maxUsers:(int)maxUsers;
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
 * provided in the onGetOnlineUsers callback of the ZoneListener.
 */
-(void)getOnlineUsers;
/**
 * Retrieves room ids of all the live rooms on the server. Result is
 * provided in the onGetAllRoomsDone callback of the ZoneListener.
 */
-(void)getAllRooms;
/**
 * Retrieves live information of the user from the server. Result is
 * provided in the onGetLiveUserInfo callback of the ZoneListener.
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
@end
