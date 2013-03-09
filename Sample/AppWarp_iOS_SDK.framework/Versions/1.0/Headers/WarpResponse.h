//
//  WarpResponse.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 27/07/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WarpMessage.h"

@interface WarpResponse : WarpMessage

+ (id) createWarpResponse;

@property Byte result;
@property Byte requestType;
@end
