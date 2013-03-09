//
//  UpdateRequestListener.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 03/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol UpdateRequestListener <NSObject>
@required
/**
 * Result of SendUpdatePeers request. The result value maps to a WarpResponseResultCode
 * @param result
 */
-(void)onSendUpdatePeersDone:(Byte)result;
@end
