RBN SDK для iOS
==============

SDK позволяет подключить ваше приложение к Russian Beacon Network.

## Подключение SDK в iOS-приложении

### Установка через CocoaPods
CocoaPods – это менеджер зависимостей, автоматизирующий и упрощающий процесс использования сторонних библиотек, таких как RBN SDK. Более подробную информацию Вы можете найти на сайте [CocoaPods](http://cocoapods.org). 

Для установки через CocoaPods добавьте в Ваш Podfile строку:

```ruby
pod 'RBN-iOS-SDK'
```

## Работа с SDK

####1. Импортируйте заголовочный файл RBN-iOS-SDK.h

```Objective-C
	#import "RBN-iOS-SDK.h"
```

####2. Инициализируйте SDK, используя в качестве параметров ваш приватный ключ и delegate для RBN-iOS-SDK.

```Objective-C
    //init RBN SDK
    [RBN-iOS-SDK setupWithAppSecret:@"YOUR_SECRET_KEY" delegate:delegate];
    // Your code ...

```

####3. Если вы планируете отправлять пользователям уведомления через Russian Beacon Network, вам необходимо в AppDelegate добавить два метода:

```Objective-C

-(void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification {    
    [RBN-iOS-SDK handleLocalNotification:notification];
}

- (void)application:(UIApplication *)application handleActionWithIdentifier:(NSString *)identifier forLocalNotification:(UILocalNotification *)notification completionHandler:(void(^)())completionHandler {
    
    [RBN-iOS-SDK handleLocalNotification:notification];
    
    completionHandler();
}
```

### Описание RBN-iOS-SDKDelegate

## Получение API ключа
Для получения уникального API ключа приложения свяжитесь с нами по адресу welike@welike.ru

## Требования

* Xcode 6 и iOS SDK 8
* iOS 7.0+ target deployment
