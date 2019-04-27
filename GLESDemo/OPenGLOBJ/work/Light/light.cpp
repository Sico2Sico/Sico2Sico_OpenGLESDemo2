//
//  light.cpp
//  OPenGLOBJ
//
//  Created by 德志 on 2019/4/26.
//  Copyright © 2019 com.aiiage.www. All rights reserved.
//

#include "light.hpp"
#include "model.hpp"
#include "Tools.hpp"
#include "ggl.hpp"
#include "framebufferobject.hpp"
#include "fullscreenquad.hpp"

glm::mat4 SpViewMatrix, SpProjectionMatrix;
glm::vec3 SPcameraPos(4.0f, 3.0f, 4.0f);
Model SPmodel;
FrameBufferObject *fbo, *blurfbo;
FullScreenQuad *fsq, *blurFSQ;

//void LightInit() {
//    SPmodel.Init("Res/Sphere.obj");
//    SPmodel.mShader->Init("Res/Sphere.vs", "Res/Sphere.fs");
//     SPmodel.SetPosition(0.0f, 0.0f, 0.0f);
//
//    /// 设置材质 环境系数
//    SPmodel.SetAmbientMaterial(0.1f, 0.1f, 0.1f, 1.0f);
//    SPmodel.mShader->SetVec4("U_AmbientLight", 0.1f, 0.1f, 0.1f, 1.0f);
//
//    /// 设置漫反射光 系数 光照点
//    SPmodel.SetDiffuseMaterial(0.4f, 0.4f, 0.4f, 1.0f);
//    SPmodel.mShader->SetVec4("U_DiffuseLight", 0.8f, 0.8f, 0.8f, 1.0f);
//    SPmodel.mShader->SetVec4("U_LightPos", 0.0f, 1.0f, 0.0f, 0.0f);
//
//
//    /// 设置镜面反射光 系数 摄像头位置
//    SPmodel.SetSpecularMaterial(1.0f, 1.0f, 1.0f, 1.0f);
//    SPmodel.mShader->SetVec4("U_SpecularLight", 1.0f, 1.0f, 1.0f, 1.0f);
//    SPmodel.mShader->SetVec4("U_CameraPos", SPcameraPos.x, SPcameraPos.y, SPcameraPos.z,1.0f);
//
//
//    SpViewMatrix = glm::lookAt(SPcameraPos,
//                             glm::vec3(0.0f, 0.0f, -1.0f),
//                             glm::vec3(0.0f,1.0f,0.0f));
//
//
//}


//void LightInit() {
//    SPmodel.Init("Res/Sphere.obj");
//    SPmodel.mShader->Init("Res/reflection.vs", "Res/reflection.fs");
//    SPmodel.mShader->SetTextureCube("U_Texture",
//                                    CreateTextureCubeFromBMP("Res/front.bmp",
//                                                             "Res/back.bmp",
//                                                             "Res/left.bmp",
//                                                             "Res/right.bmp",
//                                                             "Res/bottom.bmp",
//                                                             "Res/top.bmp"));
//    SPmodel.SetPosition(0.0f, 0.0f, 0.0f);
//    SPmodel.mShader->SetVec4("U_CameraPos",
//                             SPcameraPos.x,
//                             SPcameraPos.y,
//                             SPcameraPos.z,
//                             1.0f);
//
//
//    SpViewMatrix = glm::lookAt(SPcameraPos,
//                               glm::vec3(0.0f, 0.0f, -1.0f),
//                               glm::vec3(0.0f,1.0f,0.0f));
//
//
//}


void LightInit() {
    SPmodel.Init("Res/Sphere.obj");
    SPmodel.mShader->Init("Res/reflection.vs", "Res/reflection.fs");
    SPmodel.mShader->SetTextureCube("U_Texture",
                                    CreateTextureCubeFromBMP("Res/front.bmp",
                                                             "Res/back.bmp",
                                                             "Res/left.bmp",
                                                             "Res/right.bmp",
                                                             "Res/bottom.bmp",
                                                             "Res/top.bmp"));
    SPmodel.SetPosition(0.0f, 0.0f, 0.0f);
    SPmodel.mShader->SetVec4("U_CameraPos",
                             SPcameraPos.x,
                             SPcameraPos.y,
                             SPcameraPos.z,
                             1.0f);


    SpViewMatrix = glm::lookAt(SPcameraPos,
                               glm::vec3(0.0f, 0.0f, -1.0f),
                               glm::vec3(0.0f,1.0f,0.0f));


    fsq = new FullScreenQuad;
    fsq->Init();
    fsq->mShader->Init("Res/fullscreenquad.vs", "Res/fullscreenquad.fs");

    blurFSQ = new FullScreenQuad;
    blurFSQ->Init();
    blurFSQ->mShader->Init("Res/fullscreenquad.vs", "Res/Gaussian.fs");
}



void LightSetViewPortSize(float width, float height) {
    SpProjectionMatrix = glm::perspective(50.0f, width / height, 0.1f, 100.0f);

    fbo = new FrameBufferObject;
    fbo->AttachColorBuffer("color", GL_COLOR_ATTACHMENT0, (int)width, (int)height);
    fbo->AttachDepthBuffer("depth", (int)width, (int)height);
    fbo->Finish();
    fsq->mShader->SetTexture("U_Texture", fbo->GetBuffer("color"));

    blurfbo = new FrameBufferObject;
    blurfbo->AttachColorBuffer("color", GL_COLOR_ATTACHMENT0, (int)width, (int)height);
    blurfbo->AttachDepthBuffer("depth",(int)width, (int)height);
    blurfbo->Finish();
    blurFSQ->mShader->SetTexture("U_Texture", blurfbo->GetBuffer("color"));
}

void LightDraw() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    blurfbo->Bind();
    SPmodel.Draw(SpViewMatrix, SpProjectionMatrix, SPcameraPos.x, SPcameraPos.y, SPcameraPos.z);
    blurfbo->Unbind();

    fbo->Bind();
    fsq->Draw();
    fbo->Unbind();

    blurFSQ->Draw();
}
