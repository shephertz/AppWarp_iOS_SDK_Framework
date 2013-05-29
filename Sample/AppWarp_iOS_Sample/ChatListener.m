//
//  ChatListener.m
//  AppWarp_iOS_Sample
//
//  Created by shephertz technologies on 23/05/13.
//  Copyright (c) 2013 shephertz technologies. All rights reserved.
//

#import "ChatListener.h"
#import "ViewController.h"

@implementation ChatListener
@synthesize helper;

-(id)initWithHelper:(id)l_helper
{
    if (self=[super init])
    {
        self.helper = l_helper;
    }
    
    return self;
}

-(void)dealloc
{
    if (self.helper)
    {
        self.helper = nil;
    }
    [super dealloc];
}

-(void)onSendChatDone:(Byte)result
{
    if (result==SUCCESS)
    {
        [helper updateResponseLabel:@"Chat Sent."];
    }
    else
    {
        [helper updateResponseLabel:[NSString stringWithFormat:@"Error Code=%d",result]];
    }
}
@end
