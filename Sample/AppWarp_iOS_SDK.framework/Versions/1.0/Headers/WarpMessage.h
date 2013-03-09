//
//  WarpMessage.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 25/07/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WarpMessage : NSObject{
}
@property(nonatomic,assign)Byte type;
@property(nonatomic,assign)Byte reserved;
@property(nonatomic,assign)Byte payloadType;
@property(nonatomic,assign)int payloadSize;
@property(retain) NSData* payload;
@end
