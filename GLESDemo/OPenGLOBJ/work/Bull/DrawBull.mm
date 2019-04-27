//
//  DrawBull.m
//  OPenGLOBJ
//
//  Created by 德志 on 2019/4/26.
//  Copyright © 2019 com.aiiage.www. All rights reserved.
//

#import "DrawBull.h"
#include "Bull.hpp"

@implementation DrawBull
+ (void) configuration{
    BullInit();
}

+ (void) SetViewPortSize:(float)width  height:(float)height{
    BullSetViewPortSize(width,height);
}

+ (void) Draw{
    BullDraw();
}
@end
