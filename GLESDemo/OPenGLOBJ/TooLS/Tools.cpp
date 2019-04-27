//
//  Tools.cpp
//  OpenGLESOBJ
//
//  Created by 德志 on 2019/4/24.
//  Copyright © 2019 com.aiiage.www. All rights reserved.
//

#include "Tools.hpp"

unsigned char* DecodeBMP(unsigned char*bmpFileData, int&width, int&height) {
    if (0x4D42 == *((unsigned short*)bmpFileData)) {
        int pixelDataOffset = *((int*)(bmpFileData + 10));
        width = *((int*)(bmpFileData + 18));
        height = *((int*)(bmpFileData + 22));
        unsigned char*pixelData = bmpFileData + pixelDataOffset;
        for (int i = 0; i < width*height * 3; i += 3) {
            unsigned char temp = pixelData[i];
            pixelData[i] = pixelData[i + 2];
            pixelData[i + 2] = temp;
        }
        return pixelData;
    }
    return nullptr;
}

GLuint CreateTexture2D(unsigned char * pixlData, int width, int height, GLenum type){
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D,texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, pixlData);
    glBindBuffer(GL_TEXTURE_2D, 0);
    return texture;
}

GLuint CreateTexture2DFromBMP(const char * bpmPath){
    int fileSize =  0;
    /// 文件加载
    unsigned char * bmpFileContent = loadFileContent(bpmPath, fileSize);
    if (bmpFileContent == nullptr) {
        return 0;
    }

    int width =0, height = 0;
    /// 解码
    unsigned char * pixelData = DecodeBMP(bmpFileContent,width, height);
    if (width == 0) {
        delete bmpFileContent;
        return 0;
    }

    /// 生成纹理
    GLuint texture = CreateTexture2D(pixelData,width,height, GL_RGB);
    delete bmpFileContent;
    return  texture;
}

GLuint CreateTextureCubeFromBMP(const char *front, const char *back, const char *left,
                                const char *right, const char *top, const char *bottom) {
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_CUBE_MAP, texture);
    int nFileSize = 0, width = 0, height = 0;
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    unsigned char *bmpFileContent = loadFileContent(front, nFileSize);
    unsigned char*pixelData = DecodeBMP(bmpFileContent, width, height);
    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelData);
    delete bmpFileContent;
    bmpFileContent = loadFileContent(back, nFileSize);
    pixelData = DecodeBMP(bmpFileContent, width, height);
    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelData);
    delete bmpFileContent;
    bmpFileContent = loadFileContent(left, nFileSize);
    pixelData = DecodeBMP(bmpFileContent, width, height);
    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelData);
    delete bmpFileContent;
    bmpFileContent = loadFileContent(right, nFileSize);
    pixelData = DecodeBMP(bmpFileContent, width, height);
    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelData);
    delete bmpFileContent;
    bmpFileContent = loadFileContent(top, nFileSize);
    pixelData = DecodeBMP(bmpFileContent, width, height);
    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelData);
    delete bmpFileContent;
    bmpFileContent = loadFileContent(bottom, nFileSize);
    pixelData = DecodeBMP(bmpFileContent, width, height);
    glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixelData);
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
    delete bmpFileContent;
    return texture;
}

