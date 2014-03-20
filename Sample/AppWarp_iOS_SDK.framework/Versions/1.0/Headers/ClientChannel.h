//
//  ClientChannel.h
//  AppWarp_Project
//
//  Created by Shephertz Technology on 24/07/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AsyncUdpSocket.h"
@class KeepAliveTask;
@interface ClientChannel : NSObject<NSStreamDelegate>
{
    AsyncUdpSocket  *udpSocket;
    NSInputStream   *inputStream;
    NSOutputStream  *outputStream;
    NSTimer         *keepAliveTimer;
    NSTimer         *keepAliveUdpTimer;
    KeepAliveTask   *keepAliveTask;
    KeepAliveTask   *keepAliveUdpTask;
    BOOL            waitingForAck;
    int             waitCounter;
    
}
@property (nonatomic, retain) KeepAliveTask     *keepAliveTask;
@property (nonatomic, retain) KeepAliveTask     *keepAliveUdpTask;
@property (nonatomic, retain) NSMutableArray    *list;
@property (nonatomic, retain) NSMutableData     *incompleteData;
@property (nonatomic, assign) BOOL              waitingForData;
@property (nonatomic, retain) NSString          *warpServerHost;
@property (nonatomic, assign) int               sessionId;
@property (nonatomic, assign) int               waitCounter;
@property (nonatomic, assign) BOOL              waitingForAck;
@property (nonatomic, assign) int             countPendingKeepAlive;


- (void)initNetworkCommunication;

- (void)sendData:(NSData*)data;
- (void)sendUdpData:(NSData*)data;
- (void)disconnect;
- (void)startKeepAlives;
- (void)startUdpKeepAlives;
- (void)invalidateKeepAliveTimer;
- (void)invalidateUdpKeepAliveTimer;
- (void)initUDP;
- (void)checkForUdpRequestType:(Byte)requestType;
@end
