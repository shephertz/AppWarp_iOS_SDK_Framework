//
//  ConnectionListener.m
//  Cocos2DSimpleGame
//
//  Created by Rajeev on 23/01/13.
//
//

#import "ConnectionListener.h"
#import "ViewController.h"

@interface ConnectionListener ()
{
    NSTimer *timer;
    float timeElapsed;
}

@end

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
        [[WarpClient getInstance] initUDP];
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
        [self startTimer];
    }
    else if (event.result==SUCCESS_RECOVERED)
    {
        [helper updateResponseLabel:@"SUCCESS_RECOVERED"];
        [self stopTimer];
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

-(void)startTimer
{
    if (!timer) {
        timeElapsed = 0;
        timer = [NSTimer scheduledTimerWithTimeInterval:5.0f target:self selector:@selector(updateTime:) userInfo:nil repeats:YES];
    }
}

-(void)stopTimer
{
    if (timer) {
        [timer invalidate];
        timer = nil;
    }
}

-(void)updateTime:(NSTimer*)l_timer
{
    timeElapsed = timeElapsed + l_timer.timeInterval;
    NSLog(@"Timer : %f",timeElapsed);
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
    NSLog(@"On onInitUDPDone invoked = %d",result);
}

@end
