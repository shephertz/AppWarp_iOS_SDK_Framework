//
//  ConnectionListener.m
//  Cocos2DSimpleGame
//
//  Created by Rajeev on 23/01/13.
//
//

#import "ConnectionListener.h"


@implementation ConnectionListener
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

-(void)onConnectDone:(ConnectEvent*) event
{
    NSLog(@"%s...name=%@...%d",__FUNCTION__,[helper userName],event.result);
    if (event.result==SUCCESS)
    {
        [[helper delegate] updateResponseLabel:@"Connection Done"];
    }
    else
    {
        [[helper delegate] updateResponseLabel:[NSString stringWithFormat:@"Connection Failed with error code = %d",event.result]];
        NSLog(@"connection failed");
        
    }
}


-(void)onDisconnectDone:(ConnectEvent*) event
{
    NSLog(@"On Disconnect invoked");
    
    if (event.result==SUCCESS)
    {
        [[helper delegate] updateResponseLabel:@"Connection Dismissed"];
    }
    else
    {
        [[helper delegate] updateResponseLabel:[NSString stringWithFormat:@"Error code = %d",event.result]];
    }
}

@end
