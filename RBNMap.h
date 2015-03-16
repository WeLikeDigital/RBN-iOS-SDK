//  Created by Darius Dark on 16/03/15.

#import <Foundation/Foundation.h>

@interface RBNMap : NSObject

/**
 Array of RBNMapLayer objects. Every layer represents single floor of building or something similar.
 */
@property (nonatomic, strong) NSArray *layers;
           

//  Map characteristic

/**
 Default map rotation angle
 */
@property (nonatomic, strong) NSNumber *initialAngle;


/**
 Default zoom-level for map. Typically used when you open the map for the first time.
 */
@property (nonatomic, strong) NSNumber *initialZoomLevel;


/**
 Default initial layer identifier for map
 */
@property (nonatomic, strong) NSString *initialLayerID;


/**
 Map center coordinates and map bounds coordinates
 */

@property (nonatomic, strong) NSNumber *centerLatitude;
@property (nonatomic, strong) NSNumber *centerLongitude;

@property (nonatomic, strong) NSNumber *southWestLatitude;
@property (nonatomic, strong) NSNumber *southWestLongitude;

@property (nonatomic, strong) NSNumber *northEastLatitude;
@property (nonatomic, strong) NSNumber *northEastLongitude;


/**
 Human-understandable ame of map that indicates place it covers.
 */
@property (nonatomic, strong) NSString *name;


/**
 Unique identifier of place, that map covers.
 */
@property (nonatomic, strong) NSString *placeID;


/**
 URL to directory, where Graph.json data for this map stores. (For routing).
 */
@property (nonatomic, strong) NSURL *graphURL;


/**
 @description Indicates update availability for this map.
 */
@property (nonatomic) BOOL updateAvailable;


+(instancetype)mapWithObject:(NSDictionary*)object;


/**
  @description dictionary for storing
 */
-(NSDictionary*)dictionaryRepresentation;

@end
