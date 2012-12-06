//
//  TestClassViewController.h
//  AppWarp_Sample
//
//  Created by Shephertz Technology on 08/08/12.
//  Copyright (c) 2012 ShephertzTechnology PVT LTD. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <AppWarp_iOS_SDK/AppWarp_iOS_SDK.h>

@interface TestClassViewController : UIViewController<ConnectionRequestListener,ZoneRequestListener>

@property(nonatomic,retain)IBOutlet UITextField *usernameTextField;
@property(nonatomic,retain)IBOutlet UILabel *resultLabel;
@property (nonatomic,retain) NSString *roomId;

-(IBAction)AuthClicked:(id)sender;
-(IBAction)roomCallsClicked:(id)sender;
-(IBAction)lobbyButtonClicked:(id)sender;
-(IBAction)chatButtonClicked:(id)sender;
-(void)updateResultLabel:(NSString*)message;
@end
