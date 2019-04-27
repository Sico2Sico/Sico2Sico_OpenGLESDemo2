//
//  Bull.cpp
//  OPenGLOBJ
//
//  Created by 德志 on 2019/4/26.
//  Copyright © 2019 com.aiiage.www. All rights reserved.
//

#include "Bull.hpp"
#include "model.hpp"
#include "Tools.hpp"
#include "ggl.hpp"

glm::mat4 BlViewMatrix, BlProjectionMatrix;
glm::vec3 BlcameraPos(0.0f,2.0f,10.0f);
Model Blmodel;


void BullInit() {
    Blmodel.Init("Res/niutou.obj");
    Blmodel.mShader->Init("Res/model.vs", "Res/model.fs");
    Blmodel.SetTexture("Res/niutou.bmp");
    Blmodel.SetPosition(0.0f, 0.0f, 0.0f);

    /// 设置材质 环境系数
    Blmodel.SetAmbientMaterial(0.1f, 0.1f, 0.1f, 1.0f);
    Blmodel.mShader->SetVec4("U_LightAmbient", 1.0f, 1.0f, 1.0f, 1.0f);

    /// 设置漫反射光 系数 光照点
    Blmodel.SetDiffuseMaterial(0.6f, 0.6f, 0.6f, 1.0f);
    Blmodel.mShader->SetVec4("U_LightDiffuse", 1.0f, 1.0f, 1.0f, 1.0f);
    Blmodel.mShader->SetVec4("U_LightPos", 0.0f, 1.0f, 1.0f, 0.0f);


    /// 设置镜面反射光 系数 摄像头位置
    Blmodel.SetSpecularMaterial(1.0f, 1.0f, 1.0f, 1.0f);
    Blmodel.mShader->SetVec4("U_LightSpecular", 1.0f, 1.0f, 1.0f, 1.0f);
    Blmodel.mShader->SetVec4("U_CameraPos", 0.0f, 0.0f, 0.0f, 1.0f);

     Blmodel.mShader->SetVec4("U_LightOpt", 32.0f, 0.0f, 0.0f, 1.0f);

    BlViewMatrix = glm::lookAt(BlcameraPos,
                               glm::vec3(0.0f, 0.0f, -1.0f),
                               glm::vec3(0.0f,1.0f,0.0f));

    Blmodel.mModelMatrix = Blmodel.mModelMatrix*glm::translate(0.0f, -3.0f, 0.0f)*glm::scale(0.05f, 0.05f, 0.05f);

    Blmodel.mModelMatrix = glm::rotate(Blmodel.mModelMatrix,-90.0f, glm::vec3(0.0f,1.0f,0.0f));

}

void BullSetViewPortSize(float width, float height) {
    BlProjectionMatrix = glm::perspective(60.0f, width / height, 0.1f, 1000.0f);
}

void BullDraw() {
    glClearColor(0.1f, 0.4f, 0.7f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Blmodel.Draw(BlViewMatrix, BlProjectionMatrix, BlcameraPos.x, BlcameraPos.y, BlcameraPos.z);
}

void testjihehan(){

    /// 长度
    float leng = glm::length(glm::vec3(2.0,2.0,3.0));

    /// 距离
    float distance = glm::distance(glm::vec3(2.0,2.0,3.0), glm::vec3(2.0,2.0,3.0));

    /// 点乘
    float dot = glm::dot(glm::vec3(2.0,2.0,3.0), glm::vec3(2.0,2.0,3.0));

    /// 叉乘
    glm::vec3 cross = glm::cross(glm::vec3(2.0,2.0,3.0), glm::vec3(2.0,2.0,3.0));

    /// 单位向量
    glm::vec3 normalize = glm::normalize(glm::vec3(2.0,2.0,3.0));

    /// 反射
    glm::vec3 reflect = glm::reflect(glm::vec3(2.0,2.0,3.0), glm::vec3(2.0,2.0,3.0));


    /// 折射
    glm::vec3 refract = glm::refract(glm::vec3(2.0,2.0,3.0), glm::vec3(2.0,2.0,3.0),0.9);

   // glm::outerProduct 返回向量的叉乘矩阵

   /// glm::transpose() 转置矩阵

   /// glm::inverse  逆矩阵
}
