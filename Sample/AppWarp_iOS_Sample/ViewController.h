//
//  ViewController.h
//  AppWarp_iOS_Sample
//
//  Created by shephertz technologies on 22/05/13.
//  Copyright (c) 2013 shephertz technologies. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ViewController : UIViewController<UITextFieldDelegate>
{
    IBOutlet UITextField *nameTextField;
    IBOutlet UILabel     *response;
    
    IBOutlet UIView *createRoomView;
    IBOutlet UITextField *roomNameTextField;
    IBOutlet UITextField *roomOwnerTextField;
    IBOutlet UITextField *maxUserTextField;
    
    IBOutlet UITextField *property1KeyTextField;
    IBOutlet UITextField *property2KeyTextField;
    IBOutlet UITextField *property3KeyTextField;
    
    IBOutlet UITextField *property1ValueTextField;
    IBOutlet UITextField *property2ValueTextField;
    IBOutlet UITextField *property3ValueTextField;
    
}

@property(nonatomic,retain) NSString *roomId;


-(void)initializeAppWarp;
-(void)updateResponseLabel:(NSString*)responseString;

-(IBAction)connectButtonAction:(id)sender;
-(IBAction)disConnectButtonAction:(id)sender;
-(IBAction)createRoomButtonAction:(id)sender;
-(IBAction)joinRoomButtonAction:(id)sender;
-(IBAction)subscribeRoomButtonAction:(id)sender;
-(IBAction)joinLobbyButtonAction:(id)sender;
-(IBAction)subscribeLobbyButtonAction:(id)sender;
-(IBAction)chatButtonAction:(id)sender;
-(IBAction)updatePeersButtonAction:(id)sender;
-(IBAction)createButtonAction:(id)sender;
-(IBAction)getAllRoomsButtonAction:(id)sender;
- (IBAction)getLiveRoomInfo:(id)sender;

@end
