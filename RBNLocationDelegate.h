//  Created by Darius Dark on 11/02/15.

@class CLLocation;

@protocol RBNLocationDelegate <NSObject>

-(void)rbnDidUpdateLocation:(CLLocation*)location fromLocation:(CLLocation*)oldLocation forLayerID:(NSString*)layerID;

@end
