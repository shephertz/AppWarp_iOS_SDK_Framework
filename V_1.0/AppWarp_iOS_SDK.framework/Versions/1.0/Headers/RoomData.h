//
//  RoomData.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 27/07/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RoomData : NSObject

/**
 * Gives the name of the room specified when the room was created.
 */
@property(nonatomic,retain)NSString *name;
/**
 * Gives the id of the room.
 */
@property(nonatomic,retain)NSString *roomId;
/**
 * Gives the owner of the room specified when the room was created.
 */
@property(nonatomic,retain)NSString *owner;
/**
 * Gives the maximum users that can join the room. It is specified when
 * the room is created.
 */
@property int maxUsers;

+(RoomData*)buildRoomData:(NSDictionary*)notifyDict;

@end
