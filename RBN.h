//  Created by Darius Dark on 06/02/15.

#import "RBNAd.h"
#import "RBNMap.h"
#import "RBNMapLayer.h"
#import <Foundation/Foundation.h>
#import "RBNConstants.h"
#import "RBNLocationDelegate.h"

@class UILocalNotification, CLLocation;

@protocol RBNDelegate <NSObject>

@optional

-(void)presentAdvertisement:(RBNAd*)ad;

-(BOOL)rbnShouldUseDefaultReporting;

#pragma mark - Location serivces feedback


/**
 @description Reporting about problems with bluetooth/location services
 @description Сообщают о возможных проблемах с Bluetooth/сервисами геолокации
 */
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
 @description Инициализирует RBN с заданным secret'ом и делегатом.
 */
+(void)setupWithAppSecret:(NSString*)secret delegate:(id<RBNDelegate>)delegate;


#pragma mark -Для объявлений

/**
 @description Возвращает массив доступных пользователю на текущий момент акций
 */
+(NSMutableArray*)availableAds;


#pragma mark -Для геолокации

/**
 @description Устанавливает новый делегат для получении информации об изменении геопозиции от RBN.
 */
+(void)setLocationDelegate:(id<RBNLocationDelegate>)delegate;


/**
 @description Устанавливает новый ключевой идентификатор локации для навигации и получения карт.
 */
+(void)setPlaceID:(NSString*)placeID;

/**
 @description Сообщает, находимся ли мы в данный момент в зоне действия биконов.
 */
+(BOOL)isInMall;

/**
    @description Данный метод вернет последюнюю известную геолокацию, определенную по биконам. Или nil, если такой нет.
 */
+(CLLocation*)latestLocation;


/**
    @description Данный метод вернет последний изместый ID этажа, на котором находился пользователь.
 */
+(NSString*)latestFloorID;



/**
 @description Возвращает объект типа RBNMap, который содержит всю необходимую информацию о картах для данного place'а.
 */
+(RBNMap*)availableMapForPlaceID:(NSString*)placeID;


/**
 @description Запускает обновление/загрузку карт для определнного place'а
 @param map объект карты для обновления
 @param progress блок, вызываемый по ходу загрзки карт
 @param completion блок, вызываемый по окончании загрузки. finished - успешно ли загружено.
 */
+(void)updateMap:(RBNMap*)map progress:(void (^)(double progress))progress andCompletion:(void (^)(BOOL finished))completion;


#pragma mark -Дополнительно

+(void)handleLocalNotification:(UILocalNotification*)notification;

@end
