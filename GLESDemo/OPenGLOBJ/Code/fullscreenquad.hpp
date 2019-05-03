//
//  fullscreenquad.hpp
//  OPenGLOBJ
//
//  Created by 德志 on 2019/4/26.
//  Copyright © 2019 com.aiiage.www. All rights reserved.
//

#ifndef fullscreenquad_hpp
#define fullscreenquad_hpp

#include <stdio.h>
#include "Tools.hpp"
#include "shader.hpp"
#include "vertexbuffer.hpp"
class FullScreenQuad{
public:
    VertexBuffer *mVertexBuffer;
    Shader *mShader;
public:
    void Init();
    void Draw();
    void DrawThreed();
    void DrawToLeftTop();
    void DrawToRightTop();
    void DrawToLeftBottom();
    void DrawToRightBottom();
    void YDXDraw(float width, float height);
};


#endif /* fullscreenquad_hpp */
