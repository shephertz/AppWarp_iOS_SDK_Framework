//
//  LobbyData.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 03/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RoomData.h"

@interface LobbyData : RoomData

/**
 * true if this is the primary lobby
 */
@property bool isPrimary;

+(LobbyData*)buildLobbyData:(NSDictionary*)notifyDict;

@end
