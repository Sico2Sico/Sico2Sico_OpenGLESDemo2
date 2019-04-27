//
//  shader.hpp
//  OpenGLESOBJ
//
//  Created by 德志 on 2019/4/25.
//  Copyright © 2019 com.aiiage.www. All rights reserved.
//

#ifndef shader_hpp
#define shader_hpp

#include <stdio.h>
#include "Tools.hpp"
#include "vertexbuffer.hpp"
using namespace std;

/// location + 纹理
struct UniformTexture {
    GLint mLocation;
    GLuint mTexture;
    UniformTexture() {
        mLocation = -1;
        mTexture = 0;
    }
};

/// location + 四方体纹理
struct UniformTextureCube {
    GLint mLocation;
    GLuint mTexture;
    UniformTextureCube() {
        mLocation = -1;
        mTexture = 0;
    }
};

/// location + vec4
struct UniformVector4f {
    GLint mLocation;
    float v[4];
    UniformVector4f() {
        mLocation = -1;
        memset(v, 0, sizeof(float) * 4);
    }
};


class Shader {

public:
    ///  编译Shader
    static GLuint CompileShader(GLenum shaderType, const char*shaderCode);

    /// 创建程序
    static GLuint CreateProgram(GLuint vsShader, GLuint fsShader);

public:

    GLuint mProgram;

    /// 存储2D纹理容器
    std::map<std::string, UniformTexture*> mUniformTextures;

    /// 存储四方体纹理容器
    std::map<std::string, UniformTextureCube*> mUniformTextureCubes;

     /// 存储vce4 GPU属性纹理 自定义的比较多
    std::map<std::string, UniformVector4f*> mUniformVec4s;

    /// M  V P
    GLint mModelMatrixLocation, mViewMatrixLocation, mProjectionMatrixLocation;

    ///  顶点坐标  颜色RGB  纹理坐标  法线(xyz) location
    GLint mPositionLocation, mColorLocation, mTexcoordLocation, mNormalLocation;

    /// 初始化设置 加载shader
    void Init(const char*vs, const char*fs);

    /// 当前绘制 bind
    void Bind(float *M, float *V, float*P);

    /// 设置纹理+添加
    void SetTexture(const char * name, const char*imagePath);

    /// 设置纹理+添加
    GLuint SetTexture(const char * name, GLuint texture);

    /// 设置纹理+添加
    GLuint SetTextureCube(const char * name, GLuint texture);

    /// 设置Vec4 类型的数据+添加
    void SetVec4(const char * name, float x, float y, float z, float w);
};


#endif /* shader_hpp */
