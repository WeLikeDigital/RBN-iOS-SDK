RBN SDK для iOS
==============

SDK позволяет подключить ваше приложение к Russian Beacon Network.

## Подключение SDK в iOS-приложении

Установка RBN-iOS-SDK происходит через dependency manager - CocoaPods. Просто добавьте в Ваш Podfile строку:

```ruby
pod 'RBN-iOS-SDK'
```
[Что такое CocoaPods?](http://cocoapods.org)


## Настройка и инициализация

#####1. Импортируйте заголовочный файл RBN.h

```Objective-C
	#import <RBN-iOS-SDK/RBN.h>
```


#####2. Инициализируйте SDK, используя ваш приватный ключ и delegate для RBN-iOS-SDK.

```Objective-C
    [RBN setupWithAppSecret:@"YOUR_SECRET_KEY" delegate:delegate];
```


#####3. В файле info.plist добавьте поле NSLocationAlwaysUsageDescription типа String. В качестве значения текст, который будет показан в приложении при запросе прав на использование геолокации.


#####4. Если вы планируете отправлять пользователям уведомления через Russian Beacon Network, необходимо в AppDelegate добавить два метода:

```Objective-C

-(void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification {    
    [RBN handleLocalNotification:notification];
}

- (void)application:(UIApplication *)application handleActionWithIdentifier:(NSString *)identifier forLocalNotification:(UILocalNotification *)notification completionHandler:(void(^)())completionHandler {
    
    [RBN handleLocalNotification:notification];
    
    completionHandler();
}
```


Это необходимо, чтобы правильно обработать переход с конкретного уведомления и показать необходимую информацию.

## Описание RBNDelegate

Этот метод будет вызван, если необходимо показать на экране страницу с акцией, информация о которой содержится в объекте ad:

```Objective-C
@optional
-(void)presentAdvertisement:(RBNAd*)ad;
```


Метод вызывается, если использование служб геолокации ограниченно на данном устройстве (iOS Restrictions):

```Objective-C
@optional
-(void)rbnRequestsDisableRestrictionForLocationServices;
```


Метод вызывается, если Службы геолокации отключены для всего устройства и требуется попросить пользователя включить их:

```Objective-C
@optional
-(void)rbnRequestsEnableLocationServices;
```

Метод вызывается, если требуемый тип службы геолокации запрещен пользователем для данного приложения. Требуется попросить его включить AlwaysAuthorization:

```Objective-C
@optional
-(void)rbnRequestsAlwaysAuthorizationLocationServices;
```

## Описание RBNAd

## Получение приватного ключа
Для получения уникального API ключа приложения свяжитесь с нами по адресу welike@welike.ru

## Требования

* Xcode 6+ и iOS SDK 8+
* iOS 7.0+ target deployment
