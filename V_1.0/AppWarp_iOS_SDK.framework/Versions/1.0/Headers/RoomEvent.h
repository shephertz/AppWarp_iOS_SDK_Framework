//
//  RoomEvent.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 27/07/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RoomData.h"
#import "WarpResponse.h"

@interface RoomEvent : NSObject

/**
 * Gives the data for the room. Will be null if the result of the
 * request is not WarpResponseResultCode.SUCCESS
 */
@property(nonatomic,retain)RoomData *roomData;
/**
 * Gives the result code of the room request.
 */
@property Byte result;

+(RoomEvent*)buildRoomEvent:(WarpResponse*)response;


@end
