//  Created by Darius Dark on 11/02/15.

@class CLLocation;

@protocol WeLikeBeaconsLocationDelegate <NSObject>

-(void)weLikeDidUpdateLocation:(CLLocation*)location fromLocation:(CLLocation*)oldLocation forLayerID:(NSString*)layerID;

@end
