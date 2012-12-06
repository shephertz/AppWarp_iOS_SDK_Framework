//
//  UpdateEvent.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 03/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UpdateEvent : NSObject

/**
 * Gives the byte array update sent to the room by one of the joined
 * users. Semantics are for the developer to decide.
 */
@property(nonatomic,retain)NSData *update;

/**
 * indicates whether the update was sent over UDP
 */
@property Boolean isUDP;

+(UpdateEvent*)buildUpdateEvent:(NSData*)notifyData :(Boolean)udp;

@end
