//  Created by Darius Dark on 08/02/15.

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, AdState) {
    AdStateNotSent = 0,
    AdStateSent,
    AdStateRead,
    AdStateActionTriggered
};

@interface WeLikeAd : NSObject

@property (nonatomic, strong) NSString *advID;
@property (nonatomic, strong) NSNumber *floor;
@property (nonatomic, strong) NSString *shopID;
@property (nonatomic, strong) NSDate *startDate;
@property (nonatomic, strong) NSDate *endTime;
@property (nonatomic, strong) NSString *pushText;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *desc;
@property (nonatomic, strong) NSURL *image;
@property (nonatomic) AdState state;
@property (nonatomic, strong)  NSArray *actions;

+(instancetype)adWithObject:(NSDictionary*)object;

-(double)totalDuration;
-(double)secondsRemains;


@end
