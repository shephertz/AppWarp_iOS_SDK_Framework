//
//  ConnectionListener.m
//  Cocos2DSimpleGame
//
//  Created by Rajeev on 23/01/13.
//
//

#import "ConnectionListener.h"
#import "ViewController.h"

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
    NSLog(@"%s......ResultCode = %d",__FUNCTION__,event.result);
    if (event.result==SUCCESS)
    {
        [helper updateResponseLabel:@"Connection Done"];
    }
    else if (event.result==AUTH_ERROR)
    {
        [helper updateResponseLabel:@"AuthError"];
    }
    else if (event.result==CONNECTION_ERR)
    {
        [helper updateResponseLabel:@"CONNECTION_ERR"];
    }
    else if (event.result==CONNECTION_ERROR_RECOVERABLE)
    {
        [helper updateResponseLabel:@"CONNECTION_ERROR_RECOVERABLE"];
    }
    else if (event.result==SUCCESS_RECOVERED)
    {
        [helper updateResponseLabel:@"SUCCESS_RECOVERED"];
    }
    else if (event.result==BAD_REQUEST)
    {
        [helper updateResponseLabel:@"BAD_REQUEST"];
    }
    else if (event.result==USER_PAUSED_ERROR)
    {
        [helper updateResponseLabel:@"USER_PAUSED_ERROR"];
    }
    else
    {
        [helper updateResponseLabel:[NSString stringWithFormat:@"Connection Failed with error code = %d",event.result]];
        NSLog(@"connection failed");
    }
}


-(void)onDisconnectDone:(ConnectEvent*) event
{
    NSLog(@"On Disconnect invoked");
    
    if (event.result==SUCCESS)
    {
        [helper updateResponseLabel:@"Connection Dismissed"];
    }
    else
    {
        [helper updateResponseLabel:[NSString stringWithFormat:@"Error code = %d",event.result]];
    }
}

-(void)onInitUDPDone:(Byte)result
{
    
}

@end
