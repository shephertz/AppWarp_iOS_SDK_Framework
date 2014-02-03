//
//  ConnectionRequestListener.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 27/07/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ConnectEvent.h"

@protocol ConnectionRequestListener <NSObject>

@required
/**
 * Invoked in response to a connect request.
 * @param event
 */
-(void)onConnectDone:(ConnectEvent*) event;

/**
 * Invoked in response to a disconnect request.
 * @param event
 */
-(void)onDisconnectDone:(ConnectEvent*) event;

/**
 * Invoked in response to a init UDP request.
 * @param result
 */
-(void)onInitUDPDone:(Byte)result;

@end
