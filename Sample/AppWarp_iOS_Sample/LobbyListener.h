//
//  LobbyListener.h
//  AppWarp_iOS_Sample
//
//  Created by shephertz technologies on 23/05/13.
//  Copyright (c) 2013 shephertz technologies. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AppWarp_iOS_SDK/AppWarp_iOS_SDK.h>

@interface LobbyListener : NSObject<LobbyRequestListener>

@property (nonatomic,retain)id helper;

-(id)initWithHelper:(id)l_helper;
@end
