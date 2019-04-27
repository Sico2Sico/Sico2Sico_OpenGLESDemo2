//
//  model.hpp
//  OpenGLESOBJ
//
//  Created by 德志 on 2019/4/25.
//  Copyright © 2019 com.aiiage.www. All rights reserved.
//

#ifndef model_hpp
#define model_hpp

#include <stdio.h>
#include "vertexbuffer.hpp"
#include "shader.hpp"
#include "Tools.hpp"
#include "ggl.hpp"
using namespace std;

class Model {
public:
    /// VBO
    VertexBuffer*mVertexBuffer;

    /// shader
    Shader*mShader;

public:
    /// 模型矩阵 可更改
    glm::mat4 mModelMatrix;

    /// 光照设置
    float *mLightViewMatrix, *mLightProjectionMatrix;

    /// 构造函数
    Model();

    /// 模型加载数据 初始化
    void Init(const char*modelPath);

    /// 绘制
    void Draw(glm::mat4 & viewMatrix, glm::mat4 projectionMatrix, float x, float y, float z);

    /// 设置模型j矩阵
    void SetPosition(float x, float y, float z);

    /// 设置环境光
    void SetAmbientMaterial(float r, float g, float b, float a);

    /// 设置漫反射
    void SetDiffuseMaterial(float r, float g, float b, float a);

    /// 设置镜面反射
    void SetSpecularMaterial(float r, float g, float b, float a);

    /// 设置添加纹理
    void SetTexture(const char*imagePath);
};



#endif /* model_hpp */
