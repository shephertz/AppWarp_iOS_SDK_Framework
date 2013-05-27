//
//  ViewController.m
//  AppWarp_iOS_Sample
//
//  Created by shephertz technologies on 22/05/13.
//  Copyright (c) 2013 shephertz technologies. All rights reserved.
//

#import "ViewController.h"
#import "AppWarpHelper.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    [[AppWarpHelper sharedAppWarpHelper] initializeAppWarp];
    [[AppWarpHelper sharedAppWarpHelper] setDelegate:self];
    
    [nameTextField setDelegate:self];
    [roomNameTextField setDelegate:self];
    [roomOwnerTextField setDelegate:self];
    [maxUserTextField setDelegate:self];
    [property1KeyTextField setDelegate:self];
    [property2KeyTextField setDelegate:self];
    [property3KeyTextField setDelegate:self];
    [property1ValueTextField setDelegate:self];
    [property2ValueTextField setDelegate:self];
    [property3ValueTextField setDelegate:self];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void)showAlertWithInfo:(NSDictionary*)alertInfo
{
    UIAlertView *alert = [[UIAlertView alloc]
                          initWithTitle: [alertInfo objectForKey:@"title"]
                          message:[alertInfo objectForKey:@"message"]
                          delegate: nil
                          cancelButtonTitle:@"OK"
                          otherButtonTitles:nil];
    [alert show];
    [alert release];
}

-(void)updateResponseLabel:(NSString*)responseString
{
    [response setText:responseString];
}

#pragma mark -- Button Actions -- 

-(IBAction)connectButtonAction:(id)sender
{
    [[AppWarpHelper sharedAppWarpHelper] setUserName:nameTextField.text];
    [[AppWarpHelper sharedAppWarpHelper] connectToWarp];
}


-(IBAction)disConnectButtonAction:(id)sender
{
    [[AppWarpHelper sharedAppWarpHelper] disconnectWarp];
}


-(IBAction)createRoomButtonAction:(id)sender
{
    [createRoomView setHidden:NO];
    [self.view bringSubviewToFront:createRoomView];
}


-(IBAction)createButtonAction:(id)sender
{
    if (roomNameTextField.text && roomNameTextField.text.length)
    {
        [[AppWarpHelper sharedAppWarpHelper] setRoomName:roomNameTextField.text];
    }
    if (roomOwnerTextField.text && roomOwnerTextField.text.length)
    {
        [[AppWarpHelper sharedAppWarpHelper] setRoomOwner:roomOwnerTextField.text];
    }
    if (maxUserTextField.text && maxUserTextField.text.length)
    {
        [[AppWarpHelper sharedAppWarpHelper] setMaxUser:[maxUserTextField.text intValue]];
    }
    
    NSMutableDictionary *properties=[NSMutableDictionary dictionaryWithCapacity:0];
    
    NSString *key = property1KeyTextField.text;
    NSString *value = property1ValueTextField.text;
    
    if (key && value && key.length && value.length)
    {
        [properties setObject:key forKey:value];
    }
    
    key = property2KeyTextField.text;
    value = property2ValueTextField.text;
    
    if (key && value && key.length && value.length)
    {
        [properties setObject:key forKey:value];
    }
    
    key = property3KeyTextField.text;
    value = property3ValueTextField.text;
    
    if (key && value && key.length && value.length)
    {
        [properties setObject:key forKey:value];
    }
    
    if (properties.count)
    {
        [[AppWarpHelper sharedAppWarpHelper] setProperties:(NSDictionary *)properties];
    }
    
    [[AppWarpHelper sharedAppWarpHelper] createRoom];
    
    [createRoomView setHidden:YES];
}


-(IBAction)joinRoomButtonAction:(id)sender
{
    [[AppWarpHelper sharedAppWarpHelper] joinRoom];
}

-(IBAction)joinLobbyButtonAction:(id)sender
{
    [[AppWarpHelper sharedAppWarpHelper] joinLobby];
}

-(IBAction)chatButtonAction:(id)sender
{
    [[AppWarpHelper sharedAppWarpHelper] sendChat:@"Hi"];
}

-(IBAction)subscribeRoomButtonAction:(id)sender
{
    [[AppWarpHelper sharedAppWarpHelper] subscribeRoom];
}

-(IBAction)subscribeLobbyButtonAction:(id)sender
{
    [[AppWarpHelper sharedAppWarpHelper] subscribeLobby];
}

-(IBAction)updatePeersButtonAction:(id)sender
{
    NSDictionary *dataDict = [NSDictionary dictionaryWithObjectsAndKeys:[[AppWarpHelper sharedAppWarpHelper] userName],@"userName",[[AppWarpHelper sharedAppWarpHelper] roomName],@"roomName",@"Hello there !",@"message", nil];
    
    
    [[AppWarpHelper sharedAppWarpHelper] updatePeers:dataDict];
}

-(IBAction)getAllRoomsButtonAction:(id)sender
{
    [[AppWarpHelper sharedAppWarpHelper] getAllRooms];
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [textField resignFirstResponder];
    return YES;
}
@end
