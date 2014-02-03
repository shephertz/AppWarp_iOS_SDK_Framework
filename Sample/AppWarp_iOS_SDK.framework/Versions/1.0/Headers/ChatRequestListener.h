//
//  ChatRequestListener.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 03/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ChatRequestListener <NSObject>
@required
/**
 * Result of SendChat request. The result value maps to a WarpResponseResultCode
 * @param result
 */
-(void)onSendChatDone:(Byte)result;
-(void)onSendPrivateChatDone:(Byte)result;

@end
