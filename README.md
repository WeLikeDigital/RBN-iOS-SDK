RBN SDK для iOS
==============

SDK позволяет подключить ваше приложение к Russian Beacon Network.

## Подключение SDK в iOS-приложении

Установка RBN-iOS-SDK происходит через CocoaPods.

[Что такое CocoaPods?](http://cocoapods.org)

Просто добавьте в Ваш Podfile строку:

```ruby
pod 'RBN-iOS-SDK'
```

## Настройка и инициализация

#####1. Импортируйте заголовочный файл RBN.h

```Objective-C
	#import <RBN-iOS-SDK/RBN.h>
```

#####2. Инициализируйте SDK, используя в качестве параметров ваш приватный ключ и delegate для RBN-iOS-SDK.

```Objective-C
    [RBN setupWithAppSecret:@"YOUR_SECRET_KEY" delegate:delegate];
```

#####3. В файле info.plist необходимо добавить поле с ключом NSLocationAlwaysUsageDescription типа String. В качестве значения указать текст, который будет показан пользователю при запросе прав на использование геолокации.


#####4. Если вы планируете отправлять пользователям уведомления через Russian Beacon Network, вам необходимо в AppDelegate добавить два метода:

```Objective-C

-(void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification {    
    [RBN handleLocalNotification:notification];
}

- (void)application:(UIApplication *)application handleActionWithIdentifier:(NSString *)identifier forLocalNotification:(UILocalNotification *)notification completionHandler:(void(^)())completionHandler {
    
    [RBN handleLocalNotification:notification];
    
    completionHandler();
}
```

Это необходимо, чтобы мы могли правильно обработать открытие пользователем конкретного уведомления и показать необходимую информацию.

### Описание RBNDelegate

## Получение API ключа
Для получения уникального API ключа приложения свяжитесь с нами по адресу welike@welike.ru

## Требования

* Xcode 6 и iOS SDK 8
* iOS 7.0+ target deployment
