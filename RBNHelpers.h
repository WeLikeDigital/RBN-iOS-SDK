//  Created by Darius Dark on 08/02/15.

#ifndef RBN_IOS_SDK_RBNHelpers_h
#define RBN_IOS_SDK_RBNHelpers_h

@import Foundation;

//This allows turn off all NSLogs in release builds
#ifdef DEBUG
#define NSLog(...) NSLog(__VA_ARGS__)
#else
#define NSLog(...) while(0)
#endif

#define SI static inline

SI void DefaultsSet(NSObject* value, NSString *key) {
    [[NSUserDefaults standardUserDefaults] setValue:value forKey:key];
}

SI id Defaults(NSString *key) {
    return [[NSUserDefaults standardUserDefaults] valueForKey:key];
}

SI void Notifty(NSString *key, id object) {
    [[NSNotificationCenter defaultCenter] postNotificationName:key object:object];
}

SI void Observe(id observer, SEL selector, NSString* key) {
    [[NSNotificationCenter defaultCenter] addObserver:observer selector:selector name:key object:nil];
}

SI void Disobserve(id observer) {
    [[NSNotificationCenter defaultCenter] removeObserver:observer];
}

SI NSString* DocumentsPath() {
    NSArray *docPaths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *docPath = docPaths[0];
    
    return docPath;
}

#endif
