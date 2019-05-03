//
//  ThreeWindows.hpp
//  OPenGLOBJ
//
//  Created by 德志 on 2019/5/3.
//  Copyright © 2019 com.aiiage.www. All rights reserved.
//

#ifndef ThreeWindows_hpp
#define ThreeWindows_hpp

#include <stdio.h>

#include "Tools.hpp"
#include "shader.hpp"
#include "vertexbuffer.hpp"
class ThreeWindows{
public:
    VertexBuffer *mVertexBuffer;
    Shader *mShader;
public:
    void Init();
    void Draw();
};

#endif /* ThreeWindows_hpp */
