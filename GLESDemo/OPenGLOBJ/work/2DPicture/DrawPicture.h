//
//  DrawPicture.h
//  OPenGLOBJ
//
//  Created by 德志 on 2019/5/1.
//  Copyright © 2019 com.aiiage.www. All rights reserved.
//

#import <Foundation/Foundation.h>
@interface DrawPicture : NSObject
+ (void) configuration;
+ (void) SetViewPortSize:(float)width  height:(float)height;
+ (void) Draw:(float)width  height:(float)height;
@end

