//
//  AllUsersEvent.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 03/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WarpResponse.h"

@interface AllUsersEvent : NSObject

/**
 * Gives the result code of the getOnlineUsers request.
 */
@property Byte result;
/**
 * Gives an array usernames for all the users.
 */
@property (nonatomic, retain) NSMutableArray *userNames;

+(AllUsersEvent*)buildAllUsersEvent:(WarpResponse*)response;

@end
