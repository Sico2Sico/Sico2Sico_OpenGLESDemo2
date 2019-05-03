//
//  PictureHandle.cpp
//  OPenGLOBJ
//
//  Created by 德志 on 2019/5/1.
//  Copyright © 2019 com.aiiage.www. All rights reserved.
//

#include "PictureHandle.hpp"
#include "fullscreenquad.hpp"
#include "framebufferobject.hpp"
#include "ThreeWindows.hpp"
#include "Tools.hpp"
#include "ggl.hpp"

FrameBufferObject *zfbo1,*zfbo2, *zblurfboH1,*zblurfboV1;
FullScreenQuad *zfsq1,*zfsq2,*zblurFSQH1,*zblurFSQV1;
ThreeWindows *zthreedWind;
void PictureInit() {

    zthreedWind = new ThreeWindows;
    zthreedWind->Init();
    zthreedWind->mShader->Init("Res/fullscreenquad.vs", "Res/fullscreenquad.fs");
    zthreedWind->mShader->SetTexture("U_Texture","Res/image-001.jpg");

    zfsq1 = new FullScreenQuad;
    zfsq1->Init();
    zfsq1->mShader->Init("Res/fullscreenquad.vs", "Res/fullscreenquad.fs");
    zfsq1->mShader->SetTexture("U_Texture","Res/image-001.jpg");


    zfsq2 = new FullScreenQuad;
    zfsq2->Init();
    zfsq2->mShader->Init("Res/fullscreenquad.vs", "Res/fullscreenquad.fs");


    zblurFSQH1 = new FullScreenQuad;
    zblurFSQH1->Init();
    zblurFSQH1->mShader->Init("Res/fullscreenquad.vs", "Res/GaussianHorizontal.fs");


    zblurFSQV1 = new FullScreenQuad;
    zblurFSQV1->Init();
    zblurFSQV1->mShader->Init("Res/fullscreenquad.vs", "Res/GaussianVertical.fs");

}
void PictureSetViewPortSize(float width, float height) {
    zfbo1 = new FrameBufferObject;
    zfbo1->AttachColorBuffer("color", GL_COLOR_ATTACHMENT0, (int)width, (int)height);
    zfbo1->AttachDepthBuffer("depth", (int)width, (int)height);
    zfbo1->Finish();
    zblurFSQH1->mShader->SetTexture("U_Texture", zfbo1->GetBuffer("color"));

    zfbo2 = new FrameBufferObject;
    zfbo2->AttachColorBuffer("color", GL_COLOR_ATTACHMENT0, (int)width, (int)height);
    zfbo2->AttachDepthBuffer("depth", (int)width, (int)height);
    zfbo2->Finish();


    zblurfboH1 = new FrameBufferObject;
    zblurfboH1->AttachColorBuffer("color", GL_COLOR_ATTACHMENT0, (int)width, (int)height);
    zblurfboH1->AttachDepthBuffer("depth",(int)width, (int)height);
    zblurfboH1->Finish();
    zblurFSQV1->mShader->SetTexture("U_Texture", zblurfboH1->GetBuffer("color"));


    zblurfboV1 = new FrameBufferObject;
    zblurfboV1->AttachColorBuffer("color", GL_COLOR_ATTACHMENT0, (int)width, (int)height);
    zblurfboV1->AttachDepthBuffer("depth", (int)width, (int)height);
    zblurfboV1->Finish();

}

void PictureDraw(float width, float height){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //多频显示
//    zthreedWind->Draw();

    //获取buffer 多频纹理
//    zfbo1->Bind();
//    zthreedWind->Draw();
//    zfbo1->Unbind();
//    zfsq2->mShader->SetTexture("U_Texture", zfbo1->GetBuffer("color"));


        //屏幕适配
//      zfsq1->YDXDraw(width, height);

        //保存当前缓存的纹理color
//    zfbo2->Bind();
//    zfsq1->YDXDraw(width, height);
//    const char * filename = "/Users/wudezhi/Desktop/videoData/tts/imagezz.jpg";
//    unsigned char * pixels = new unsigned char[width*height*4];
//    glReadPixels(0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
//    SOIL_save_image(filename,SOIL_SAVE_TYPE_TGA,width, height, 4,pixels);
//    delete[] pixels;
//    pixels = nullptr;
//    zfbo2->Unbind();



}
