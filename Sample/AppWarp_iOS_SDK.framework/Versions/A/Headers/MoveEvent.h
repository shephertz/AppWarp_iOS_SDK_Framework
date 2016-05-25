//
//  MoveEvent.h
//  AppWarp_Project
//
//  Created by shephertz technologies on 24/07/13.
//  Copyright (c) 2013 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WarpResponse.h"
@interface MoveEvent : NSObject
{
    
}
@property(nonatomic,retain) NSString *sender;
@property(nonatomic,retain) NSString *moveData;
@property(nonatomic,retain) NSString *nextTurn;
@property(nonatomic,retain) NSString *roomId;

+(MoveEvent*)buildMoveData:(NSDictionary*)notifyDict;
+(NSMutableArray*)buildMoveHistoryArray:(WarpResponse*)msg;
@end
