//
//  TurnBasedRoomListener.h
//  AppWarp_Project
//
//  Created by shephertz technologies on 24/07/13.
//  Copyright (c) 2013 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MoveEvent.h"

@protocol TurnBasedRoomListener <NSObject>

@optional
/**
 * Invoked when a response for a sendMove request is received.
 * @param result
 */
-(void)onSendMoveDone:(Byte)result;

/**
 * Invoked when a response for a startGame request is received. Room subscribers will receive this.
 * @param result
 */
-(void)onStartGameDone:(Byte)result;

/**
 * Invoked when a response for a stopGame request is received. Room subscribers will receive this.
 * @param result
 */
-(void)onStopGameDone:(Byte)result;

/**
 * Invoked when a response for a getMoveHistory request is received.
 * @param result
 */
-(void)onGetMoveHistoryDone:(Byte)result moves:(NSMutableArray*)movesArray;

/**
 * Invoked when a request from the server is received to set the next turn
 * @param lastTurn
 */
-(void)onNextTurnRequest:(NSString*)lastTurn;

/**
 * Invoked when a response from the server for setNextTurn request is received
 * @param result
 */
-(void)onSetNextTurnDone:(Byte)result;
@end
