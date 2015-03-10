//  Created by Darius Dark on 06/02/15.

#import "RBNAd.h"
#import <Foundation/Foundation.h>
#import "RBNConstants.h"
#import "RBNLocationDelegate.h"

@class UILocalNotification, CLLocation;

@protocol RBNDelegate <NSObject>

@optional

-(void)presentAdvertisement:(RBNAd*)ad;

-(BOOL)rbnShouldUseDefaultReporting;

#pragma mark - Location serivces feedback

//Reporting about problems with bluetooth/location services
-(void)rbnRequestsDisableRestrictionForLocationServices;
-(void)rbnRequestsEnableBluetooth;
-(void)rbnRequestsEnableLocationServices;
-(void)rbnRequestsAlwaysAuthorizationLocationServices;
-(void)rbnReportsThatBLEIsNotSupportedForThisDevice;

//Reports that everything is cool.
-(void)rbnReportsThatBeaconsModuleRunning;


@end

@interface RBN : NSObject

#pragma mark -Для инициализации

/**
 Инициализирует RBN с заданным secret'ом и делегатом.
 */
+(void)setupWithAppSecret:(NSString*)secret delegate:(id<RBNDelegate>)delegate;


#pragma mark -Для объявлений

/**
 Возвращает массив доступных пользователю на текущий момент акций
 */
+(NSMutableArray*)availableAds;


#pragma mark -Для геолокации

/**
 Устанавливает новый делегат для получении информации об изменении геопозиции от RBN.
 */
+(void)setLocationDelegate:(id<RBNLocationDelegate>)delegate;


/**
 Устанавливает новый ключевой идентификатор локации для навигации и получения карт.
 */
+(void)setPlaceID:(NSString*)placeID;


/**
    Данный метод вернет последюнюю известную геолокацию, определенную по биконам. Или nil, если такой нет.
 */
+(CLLocation*)latestLocation;


/**
    Данный метод вернет последний изместый ID этажа, на котором находился пользователь.
 */
+(NSString*)latestFloorID;

#pragma mark -Дополнительно

+(void)handleLocalNotification:(UILocalNotification*)notification;

@end
