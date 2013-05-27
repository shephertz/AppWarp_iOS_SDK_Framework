//
//  AppWarpHelper.h
//  AppWarp_iOS_Sample
//
//  Created by shephertz technologies on 22/05/13.
//  Copyright (c) 2013 shephertz technologies. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ViewController.h"

@interface AppWarpHelper : NSObject
{
}

@property(nonatomic,retain) id delegate;
@property (nonatomic,retain) NSString *roomId;
@property (nonatomic,retain) NSString *roomName;
@property (nonatomic,retain) NSString *roomOwner;
@property (nonatomic,assign) int        maxUser;
@property (nonatomic,retain) NSString *userName;
@property (nonatomic,retain) NSDictionary *properties;

+(AppWarpHelper *)sharedAppWarpHelper;


-(void)initializeAppWarp;
//-(void)setCustomDataWithData:(NSData*)data;
//-(void)receivedEnemyStatusData:(NSData*)data;
-(void)disconnectWarp;
-(void)connectToWarp;
-(void)createRoom;
-(void)joinRoom;
-(void)subscribeRoom;
-(void)subscribeLobby;
-(void)joinLobby;
-(void)sendChat:(NSString*)message;
-(void)updatePeers:(NSDictionary *)dataDict;
-(void)getAllRooms;
@end
