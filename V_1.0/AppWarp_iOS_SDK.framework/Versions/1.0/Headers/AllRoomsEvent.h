//
//  AllRoomsEvent.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 03/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WarpResponse.h"

@interface AllRoomsEvent : NSObject

/**
 * Gives the result code of the getAllRooms request.
 */
@property Byte result;
/**
 * Gives an array of room ids.
 */

@property (nonatomic, retain) NSMutableArray *roomIds;

+(AllRoomsEvent*)buildAllRoomsEvent:(WarpResponse*)response;

@end
