//
//  vertexbuffer.hpp
//  OpenGLESOBJ
//
//  Created by 德志 on 2019/4/25.
//  Copyright © 2019 com.aiiage.www. All rights reserved.
//

#ifndef vertexbuffer_hpp
#define vertexbuffer_hpp

#include <stdio.h>
#include "ggl.hpp"


/// 单个VBO单元
struct Vertex {
    /// 顶点坐标
    float Position[4];

    /// 颜色
    float Color[4];

    /// 纹理坐标
    float Texcoord[4];

    /// 法向量
    float Normal[4];
};


class VertexBuffer {

public:
    /// 创建VBO 先申请一块GPU空间 data可以为nil
    static GLuint CreateBufferObject(GLenum bufferType, GLsizeiptr size, GLenum usage, void*data = nullptr);

public:
    /// VBO数据
    Vertex *mVertexes;

    /// 顶点数据个数
    int mVertexCount;

    /// VBO 标识
    GLuint mVBO;

    /// Set--->mVertexCount 并创建VBO --->CreateBufferObject
    void SetSize(int vertexCount);

    /// 添加设置顶点数据
    void SetPosition(int index, float x, float y, float z, float w = 1.0f);

    /// 添加设置颜色
    void SetColor(int index, float r, float g, float b, float a = 1.0);

    /// 设置纹理坐标
    void SetTexcoord(int index, float x, float y);

    /// 设置法向量
    void SetNormal(int index, float x, float y, float z);

    /// 当前bind
    void Bind();

    /// 取消当前bind
    void Unbind();

    /// 获取单个 Vertex
    Vertex&Get(int index);
};

#endif /* vertexbuffer_hpp */
