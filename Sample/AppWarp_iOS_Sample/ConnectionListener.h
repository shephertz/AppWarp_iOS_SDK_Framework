//
//  ConnectionListener.h
//  Cocos2DSimpleGame
//
//  Created by Rajeev on 23/01/13.
//
//

#import <Foundation/Foundation.h>
#import <AppWarp_iOS_SDK/AppWarp_iOS_SDK.h>

@interface ConnectionListener : NSObject<ConnectionRequestListener>

@property (nonatomic,retain)id helper;


-(id)initWithHelper:(id)l_helper;

@end
