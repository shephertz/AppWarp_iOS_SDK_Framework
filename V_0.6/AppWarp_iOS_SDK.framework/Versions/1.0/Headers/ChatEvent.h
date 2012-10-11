//
//  ChatEvent.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 03/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WarpResponse.h"

@interface ChatEvent : NSObject

/**
 * gives the sender of the chat message
 */
@property (nonatomic, retain) NSString* sender;
/**
 * Gives the actual chat message sent
 */
@property (nonatomic, retain) NSString* message;
/**
 * Gives the id of the room in which the chat was sent.
 */
@property (nonatomic, retain) NSString* locId;
/**
 * true if the location is a lobby
 */
@property bool isLocationLobby;


+(ChatEvent*)buildChatEvent:(NSDictionary*)notifyDict;

@end
