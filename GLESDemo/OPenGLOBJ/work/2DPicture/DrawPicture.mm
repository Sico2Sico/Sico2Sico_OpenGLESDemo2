//
//  DrawPicture.m
//  OPenGLOBJ
//
//  Created by 德志 on 2019/5/1.
//  Copyright © 2019 com.aiiage.www. All rights reserved.
//

#import "DrawPicture.h"
#import "PictureHandle.hpp"

@implementation DrawPicture
+ (void) configuration{
    PictureInit();
}

+ (void) SetViewPortSize:(float)width  height:(float)height{
    PictureSetViewPortSize( width,  height);
}

+ (void) Draw:(float)width  height:(float)height{
    PictureDraw(width,  height);
}


@end
