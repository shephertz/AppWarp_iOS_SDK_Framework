//
//  MatchedRoomsEvent.h
//  AppWarp_Project
//
//  Created by shephertz technologies on 21/05/13.
//  Copyright (c) 2013 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RoomData.h"
#import "WarpResponse.h"

@interface MatchedRoomsEvent : NSObject
/**
 * Gives the result code of the connection request.
 */
@property Byte result;

/**
 * Gives the data for the room. Will be null if the result of the
 * request is not WarpResponseResultCode.SUCCESS
 */
@property(nonatomic,retain)NSArray *roomData;

+(MatchedRoomsEvent*)buildMatchedRoomsEvent:(WarpResponse*)response;
@end
