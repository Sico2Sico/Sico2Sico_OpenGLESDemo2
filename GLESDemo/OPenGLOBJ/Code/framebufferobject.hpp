//
//  framebufferobject.hpp
//  OPenGLOBJ
//
//  Created by 德志 on 2019/4/25.
//  Copyright © 2019 com.aiiage.www. All rights reserved.
//

#ifndef framebufferobject_hpp
#define framebufferobject_hpp

#include <stdio.h>
#include "Tools.hpp"
using namespace std;

class FrameBufferObject{
public:
    GLuint mFrameBufferObject;
    GLint mPrevFrameBuffer;
    std::map<std::string, GLuint> mBuffers;
    std::vector<GLenum> mDrawBuffers;
public:
    FrameBufferObject();
    void AttachColorBuffer(const char*bufferName,GLenum attachment,int width,int height);
    void AttachDepthBuffer(const char*bufferName, int width, int height);
    void Finish();
    void Bind();
    void Unbind();
    GLuint GetBuffer(const char*bufferName);
};


#endif /* framebufferobject_hpp */
