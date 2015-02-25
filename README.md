RBN SDK для iOS
==============

SDK позволяет подключить ваше приложение к Russian Beacon Network.

### Подключение SDK в iOS-приложении

### Установка через CocoaPods
CocoaPods – это менеджер зависимостей, автоматизирующий и упрощающий процесс использования сторонних библиотек, таких как RBN SDK. Более подробную информацию Вы можете найти на сайте [CocoaPods](http://cocoapods.org). 

Для установки через CocoaPods добавьте в Ваш Podfile строку:

```ruby
pod 'RBN-iOS-SDK'
```

## Работа с SDK

### Инициализация SDK

1. Поместите этот код в метод делегата приложения:

```Objective-C
	#import "WeLikeBeacons.h"
 
  - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    //init RBN SDK
    [WeLikeBeacons startSession:@"YOUR_API_KEY"];
    // Your code ...
  }
```


## Получение API ключа
Для получения уникального API ключа приложения свяжитесь с нами по адресу welike@welike.ru

## Требования

* Xcode 6 и iOS SDK 8
* iOS 7.0+ target deployment
