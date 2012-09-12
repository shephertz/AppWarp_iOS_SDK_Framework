//
//  WarpNotifyMessage.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 03/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WarpMessage.h"

@interface WarpNotifyMessage : WarpMessage

@property Byte updateType;

+ (id) createWarpNotify;

@end
