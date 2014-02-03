//
//  LiveRoomInfoEvent.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 03/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WarpResponse.h"
#import "RoomEvent.h"

@interface LiveRoomInfoEvent : RoomEvent

/**
 * gives a string array of usernames
 */
@property (nonatomic, retain) NSMutableArray *joinedUsers;
/**
 * Gives the custom data associated with the room.
 */
@property (nonatomic, retain) NSString* customData;

/**
 * Gives the properties associated with the room.
 */
@property (nonatomic, retain) NSDictionary* properties;
/**
 * Gives the locked properties associated with the room.
 */
@property (nonatomic, retain) NSDictionary* lockPropeties;


/**
 * Gives the result code 
 */
@property Byte result;


+(LiveRoomInfoEvent*)buildLiveRoomInfoEvent:(WarpResponse*)response;

@end
