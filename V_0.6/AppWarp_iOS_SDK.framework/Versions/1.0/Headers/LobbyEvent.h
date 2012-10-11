//
//  LobbyEvent.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 03/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LobbyData.h"
#import "LobbyEvent.h"
#import "WarpResponse.h"

@interface LobbyEvent : NSObject
/**
 * Gives the data for the lobby.
 */
@property (nonatomic, retain) LobbyData* info;
/**
 * Gives the result code of the lobby request.
 */
@property Byte result;


+(LobbyEvent*)buildLobbyEvent:(WarpResponse*)response;
@end
