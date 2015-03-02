RBN SDK для iOS
==============

SDK позволяет подключить ваше приложение к Russian Beacon Network.

## Как добавить в проект?

Установка RBN-iOS-SDK происходит через dependency manager - CocoaPods. Просто добавьте в Ваш Podfile строку:

```ruby
pod 'RBN-iOS-SDK'
```
[Что такое CocoaPods?](http://cocoapods.org)


## Базовая настройка

#####1. Импортируйте заголовочный файл RBN.h

```Objective-C
	#import <RBN-iOS-SDK/RBN.h>
```


#####2. Инициализируйте SDK, используя ваш приватный ключ и delegate для RBN-iOS-SDK.

```Objective-C
    [RBN setupWithAppSecret:@"YOUR_SECRET_KEY" delegate:delegate];
```


#####3. В файле info.plist добавьте поле NSLocationAlwaysUsageDescription типа String. В качестве значения текст, который будет показан в приложении при запросе прав на использование геолокации.


## Чтобы показывать рекламу

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

Это необходимо, чтобы SDK обработал переход пользователя с уведомления и вызвал метод, который описан в следующем пункте.

#####5. Затем добавим в наш RBNDelegate метод, который будет сообщать о том, что нужно показать объявление:

```Objective-C
-(void)presentAdvertisement:(RBNAd*)ad {
	//Ваш код. Обработайте пришедший объект RBNAd, содержащий информацию о рекламном объявлении, здесь. 
}
```

## Описание RBNDelegate

Перечисленные ниже методы являются **опциональными**. В случае, если вы не опишете их в вашем классе-делегате, наш SDK будет использовать их базовые реализации, описанные нами. 
Так, например, совсем не обязательно, чтобы ваш delegate отвечал на метод rbnRequestsEnableBluetooth. В то же время, если вы хотите запрограммировать иной сценарий поведения при этом событии, необходимо определить этот метод.

```Objective-C
@optional
```

Этот метод будет вызван, если необходимо показать на экране страницу с акцией, информация о которой содержится в объекте ad:

```Objective-C
-(void)presentAdvertisement:(RBNAd*)ad;
```


Метод вызывается, если использование служб геолокации **ограниченно на данном устройстве** (iOS Restrictions):

```Objective-C
-(void)rbnRequestsDisableRestrictionForLocationServices;
```


Метод вызывается, если службы геолокации отключены **для всего устройства** и требуется попросить пользователя включить их:

```Objective-C
-(void)rbnRequestsEnableLocationServices;
```

Метод вызывается, если требуемый тип службы геолокации запрещен пользователем **для данного приложения**. Нужно попросить его включить AlwaysAuthorization:

```Objective-C
-(void)rbnRequestsAlwaysAuthorizationLocationServices;
```

Метод вызывается, есть BLE недоступен на данном устройстве.

```Objective-C
-(void)rbnReportsThatBLEIsNotSupportedForThisDevice;
```

Метод вызывается, если пользователь по каким-то причинам отключил блютуз.

```Objective-C
-(void)rbnRequestsEnableBluetooth;
```

## Описание RBNAd
## Описание RBNLocationDelegate

## Получение приватного ключа
Для получения уникального API ключа приложения свяжитесь с нами по адресу welike@welike.ru

## Требования

* Xcode 6+ и iOS SDK 8+
* iOS 7.0+ target deployment
