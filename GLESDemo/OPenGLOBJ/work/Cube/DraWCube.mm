//
//  DraWCube.m
//  OPenGLOBJ
//
//  Created by 德志 on 2019/4/25.
//  Copyright © 2019 com.aiiage.www. All rights reserved.
//

#import "DraWCube.h"
#include "scence.hpp"

unsigned char * loadFileContent(const char* path , int& filesize){
    unsigned char * fileContent = nullptr;
    filesize = 0;
    NSString * pathFile = [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:path] ofType:nil];
    NSData * data = [NSData dataWithContentsOfFile:pathFile];
    if ([data length] > 0 ) {
        filesize = [data length];
        fileContent = new unsigned char[filesize+1];
        memcpy(fileContent,[data bytes], filesize);
        fileContent[filesize]= '\0';
    }

    return  fileContent;
}

const char * backoutBundlePath(const char* imagePath){
    NSString * pathFile = [[NSBundle mainBundle] pathForResource:[NSString stringWithUTF8String:imagePath] ofType:nil];
    return  [pathFile UTF8String];
}


@implementation DraWCube

+ (void) configuration{
    Init();
}

+ (void) SetViewPortSize:(float)width  height:(float)height{
    SetViewPortSize(width, height);
}

+ (void) DrawCube{
    Draw();
}




@end
