//
//  ClientChannel.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 24/07/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AsyncUdpSocket.h"

@interface ClientChannel : NSObject<NSStreamDelegate>{
    AsyncUdpSocket *udpSocket;
}
@property (nonatomic, retain) NSInputStream *inputStream;
@property (nonatomic, retain) NSOutputStream *outputStream;
@property (nonatomic, retain) NSMutableArray *list;
@property (nonatomic, retain) NSMutableData *incompleteData;
@property (nonatomic, assign) BOOL waitingForData;
- (void)initNetworkCommunication;

- (void)sendData:(NSData*)data;
- (void)sendUdpData:(NSData*)data;
-(void)disconnect;

@end
