//
//  LiveUserInfoEvent.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 03/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WarpResponse.h"

@interface LiveUserInfoEvent : NSObject

/**
 * Gives the result code of the getLiveUserInfo request.
 */
@property Byte result;
/**
 * Gives the loc id of the user
 */
@property (nonatomic,retain) NSString *locationId;
/**
 * Gives the name of the user
 */
@property (nonatomic,retain) NSString *name;
/**
 * Gives the custom data associated with the user
 */
@property (nonatomic,retain) NSString *customData;
/**
 * true if the user is in a lobby
 */
@property bool isLocationLobby;


+(LiveUserInfoEvent*)buildLiveUserInfoEvent:(WarpResponse*)response;


@end
