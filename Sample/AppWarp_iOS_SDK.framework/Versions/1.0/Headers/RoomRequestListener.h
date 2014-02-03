//
//  RoomRequestListener.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 03/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RoomEvent.h"
#import "LiveRoomInfoEvent.h"

@protocol RoomRequestListener <NSObject>

@required
/**
 * Invoked in response to a subscribeRoom request.
 * @param event
 */
-(void)onSubscribeRoomDone:(RoomEvent*)roomEvent;
/**
 * Invoked in response to a UnSubscribeRoom request.
 * @param event
 */
-(void)onUnSubscribeRoomDone:(RoomEvent*)roomEvent;
/**
 * Invoked in response to a joinRoom request.
 * @param event
 */
-(void)onJoinRoomDone:(RoomEvent*)roomEvent;
/**
 * Invoked in response to a leaveRoom request.
 * @param event
 */
-(void)onLeaveRoomDone:(RoomEvent*)roomEvent;
/**
 * Invoked in response to a getLiveRoomInfo request.
 * @param event
 */
-(void)onGetLiveRoomInfoDone:(LiveRoomInfoEvent*)event;
/**
 * Invoked in response to a setCustomRoomData request.
 * @param event
 */
-(void)onSetCustomRoomDataDone:(LiveRoomInfoEvent*)event;
/**
 * Invoked in response to a updateRoomProperties request.
 * @param event
 */
-(void)onUpdatePropertyDone:(LiveRoomInfoEvent*)event;

/*
 * Invoked in response to lock room property to any room.
 * @param result
 */
-(void)onLockPropertiesDone:(Byte)result;

/*
 * Invoked in response to unlock room property to any room.
 * @param result
 */
-(void)onUnlockPropertiesDone:(Byte)result;


@end