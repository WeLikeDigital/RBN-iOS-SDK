//  Created by Darius Dark on 06/02/15.

#import "WeLikeAd.h"
#import <Foundation/Foundation.h>
#import "WeLikeBeaconsConstants.h"
#import "WeLikeBeaconsLocationDelegate.h"

@class UILocalNotification, UIImage;

@protocol WeLikeBeaconsDelegate <NSObject>

-(UIImage*)appIcon;
-(void)presentAdvertisement:(WeLikeAd*)ad;

@end

@interface WeLikeBeacons : NSObject

//Setup & customization
+(void)setupWithAppSecret:(NSString*)secret delegate:(id<WeLikeBeaconsDelegate>)delegate;


//Methods for developers

+(NSMutableArray*)availableAds;

//For Location
+(void)setLocationDelegate:(id<WeLikeBeaconsLocationDelegate>)delegate;
+(void)setPlaceID:(NSString*)placeID;

//System
+(void)handleLocalNotification:(UILocalNotification*)notification;

@end
