//  Created by Darius Dark on 06/02/15.

#import "RBNAd.h"
#import <Foundation/Foundation.h>
#import "RBNConstants.h"
#import "RBNLocationDelegate.h"

@class UILocalNotification;

@protocol RBNDelegate <NSObject>

@optional

-(void)presentAdvertisement:(RBNAd*)ad;


//Location serivces feedback:

-(void)rbnRequestsDisableRestrictionForLocationServices;

-(void)rbnRequestsEnableBluetooth;
-(void)rbnRequestsEnableLocationServices;
-(void)rbnRequestsAlwaysAuthorizationLocationServices;

-(void)rbnReportsThatBLEIsNotSupportedForThisDevice;


@end

@interface RBN : NSObject

//Setup & customization
+(void)setupWithAppSecret:(NSString*)secret delegate:(id<RBNDelegate>)delegate;


//Methods for developers

+(NSMutableArray*)availableAds;

//For Location
+(void)setLocationDelegate:(id<RBNLocationDelegate>)delegate;
+(void)setPlaceID:(NSString*)placeID;

//System
+(void)handleLocalNotification:(UILocalNotification*)notification;

@end
