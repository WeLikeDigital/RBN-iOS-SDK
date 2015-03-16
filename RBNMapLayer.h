//  Created by Darius Dark on 16/03/15.

#import <Foundation/Foundation.h>

@interface RBNMapLayer : NSObject


/**
 The last time layer updated
 */
@property (nonatomic, strong) NSDate *timestamp;


/**
    Humam-readable name of layer
 */
@property (nonatomic, strong) NSString *layerName;


/**
 Unique identifier of layer
 */
@property (nonatomic, strong) NSString *layerIdentifier;


/**
  Unique identifier of place of this layer
 */
@property (nonatomic, strong) NSString *placeID;


/**
 Path in files-directory for layer data
 */
-(NSString*)pathForLayer;


/**
 Indicates, wether or not layer is basement of map
 */
-(BOOL)isBasement;


+(instancetype)layerWithObject:(NSDictionary*)object;


-(NSDictionary*)dictionaryRepresentation;


/**
 Private properties
 */


/**
 URL for downloading layer
 */
@property (nonatomic, strong) NSURL *layerDownloadLink;


/**
 Size of layer in bytes
 */
@property (nonatomic, strong) NSNumber *layerSize;


@end
