//
//  ZoneRequestListener.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 27/07/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RoomEvent.h"
#import "AllRoomsEvent.h"
#import "LiveUserInfoEvent.h"
#import "AllUsersEvent.h"
#import "MatchedRoomsEvent.h"

@protocol ZoneRequestListener <NSObject>

@required
/**
 * Invoked in response to a createRoom request.
 * @param event
 */
-(void)onCreateRoomDone:(RoomEvent*)roomEvent;
/**
 * Invoked in response to a deleteRoom request.
 * @param event
 */
-(void)onDeleteRoomDone:(RoomEvent*)roomEvent;
/**
 * Invoked in response to a getAllRooms request.
 * @param event
 */
-(void)onGetAllRoomsDone:(AllRoomsEvent*)event;
/**
 * Invoked in response to a getOnlineUsers request.
 * @param event
 */
-(void)onGetOnlineUsersDone:(AllUsersEvent*)event;
/**
 * Invoked in response to a getLiveUserInfo request.
 * @param event
 */
-(void)onGetLiveUserInfoDone:(LiveUserInfoEvent*)event;
/**
 * Invoked in response to a setCustomRoomData request.
 * @param event
 */
-(void)onSetCustomUserDataDone:(LiveUserInfoEvent*)event;

/**
 * Invoked in response to a getMatchMaking Rooms request.
 * @param event
 */
-(void)onGetMatchedRoomsDone:(MatchedRoomsEvent*)event;

@end
