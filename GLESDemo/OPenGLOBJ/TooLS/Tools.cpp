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

//#define GL_REPEAT                                        0x2901
//#define GL_CLAMP_TO_EDGE                                 0x812F
//#define GL_MIRRORED_REPEAT
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, pixlData);
    glBindBuffer(GL_TEXTURE_2D, 0);
    return texture;
}

GLuint CreateTexture2DFromBMP(const char*bmpPath) {

    //    int nFileSize = 0;
    //    unsigned char *bmpFileContent = LoadFileContent(bmpPath, nFileSize);
    //    if (bmpFileContent == nullptr) {
    //        return 0;
    //    }
    //    int bmpWidth = 0, bmpHeight = 0;
    //    unsigned char*pixelData = DecodeBMP(bmpFileContent, bmpWidth, bmpHeight);
    //    if (bmpWidth == 0) {
    //        delete bmpFileContent;
    //        return 0;
    //    }
    const char * imagePath = backoutBundlePath(bmpPath);
    int bmpWidth = 0, bmpHeight = 0, chanles =0;
    unsigned char * pixelData =  SOIL_load_image(imagePath, &bmpWidth, &bmpHeight,&chanles, SOIL_LOAD_RGB);
    GLuint texture = CreateTexture2D(pixelData, bmpWidth, bmpHeight, GL_RGB);
    //    delete bmpFileContent;
    //    bmpFileContent = nullptr;
    return texture;
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

