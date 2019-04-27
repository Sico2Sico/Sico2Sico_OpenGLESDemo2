//
//  DrawLight.m
//  OPenGLOBJ
//
//  Created by 德志 on 2019/4/26.
//  Copyright © 2019 com.aiiage.www. All rights reserved.
//

#import "DrawLight.h"
#include "light.hpp"

@implementation DrawLight

+ (void) configuration{
    LightInit();
}
+ (void) SetViewPortSize:(float)width  height:(float)height{
    LightSetViewPortSize(width, height);
}


+ (void) Draw{
    LightDraw();
}

@end
