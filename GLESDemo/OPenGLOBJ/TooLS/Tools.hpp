//
//  Tools.hpp
//  OpenGLESOBJ
//
//  Created by 德志 on 2019/4/24.
//  Copyright © 2019 com.aiiage.www. All rights reserved.
//

#ifndef Tools_hpp
#define Tools_hpp

#include <stdio.h>
#include "ggl.hpp"


/**
 记载文件资源

 @param path 路径
 @param filesize 文件大小
 @return
 */
unsigned char * loadFileContent(const char* path , int& filesize);



/**
 解码位图

 @param bmpFileData 位图文件
 @param int&width 宽度
 @param int&heigh 高度
 @param type 数据类型 GL_RGB GL_
 @return <#return value description#>
 */

unsigned char * DecodeBMP(unsigned char* bmpFileData, int&width,int&height, GLenum type);


/**
 data 创建纹理

 @param pixlData data数据
 @param width 纹理宽
 @param heigh 高
 @param type 数据类型 GL_RGB GL_
 @return <#return value description#>
 */
GLuint CreateTexture2D(unsigned char * pixlData, int width, int height, GLenum type);



/**
使用路径创建纹理

 @param bpmPath 资源路径
 @return 返回纹理
 */
GLuint CreateTexture2DFromBMP(const char * bpmPath);



/**
 创建四方体纹理

 @param front <#front description#>
 @param back <#back description#>
 @param left <#left description#>
 @param right <#right description#>
 @param top <#top description#>
 @param bottom <#bottom description#>
 @return <#return value description#>
 */
GLuint CreateTextureCubeFromBMP(const char *front, const char *back, const char *left,
                                const char *right, const char *top, const char *bottom);

#endif
