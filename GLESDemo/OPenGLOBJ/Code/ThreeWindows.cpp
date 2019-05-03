//
//  ThreeWindows.cpp
//  OPenGLOBJ
//
//  Created by 德志 on 2019/5/3.
//  Copyright © 2019 com.aiiage.www. All rights reserved.
//

#include "ThreeWindows.hpp"

void ThreeWindows::Init(){
    mVertexBuffer = new VertexBuffer;
    mVertexBuffer->SetSize(12);

    mVertexBuffer->SetTexcoord(0, 0.0f, 0.0f);
    mVertexBuffer->SetTexcoord(1, 1.0f, 0.0f);
    mVertexBuffer->SetTexcoord(2, 0.0f, 1.0f);

    mVertexBuffer->SetTexcoord(3, 0.0f, 1.0f);
    mVertexBuffer->SetTexcoord(4, 1.0, 1.0f);
    mVertexBuffer->SetTexcoord(5, 1.0f, 0.0f);


    mVertexBuffer->SetTexcoord(6, 0.0f, 0.0f);
    mVertexBuffer->SetTexcoord(7, 1.0f, 0.0f);
    mVertexBuffer->SetTexcoord(8, 0.0f, 1.0f);

    mVertexBuffer->SetTexcoord(9, 0.0f, 1.0f);
    mVertexBuffer->SetTexcoord(10, 1.0f, 1.0f);
    mVertexBuffer->SetTexcoord(11, 1.0f, 0.0f);


    mShader = new Shader;
}
void ThreeWindows::Draw(){
    float identity[] = {
        1.0f,0.0f,0.0f,0.0f,
        0.0f,1.0f,0.0f,0.0f,
        0.0f,0.0f,1.0f,0.0f,
        0.0f,0.0f,0.0f,1.0f,
    };
    mVertexBuffer->SetPosition(0, -1.0f, -1.0f, 0.0f);
    mVertexBuffer->SetPosition(1, 0.0f, -1.0f, 0.0f);
    mVertexBuffer->SetPosition(2, -1.0f, 1.0f, 0.0f);

    mVertexBuffer->SetPosition(3,  -1.0f, 1.0f, 0.0f);
    mVertexBuffer->SetPosition(4, 0.0f, 1.0f, 0.0f);
    mVertexBuffer->SetPosition(5, 0.0, -1.0f, 0.0f);

    mVertexBuffer->SetPosition(6, 0.0, -1.0f, 0.0f);
    mVertexBuffer->SetPosition(7, 1.0f, -1.0f, 0.0f);
    mVertexBuffer->SetPosition(8, 0.0, 1.0f, 0.0f);

    mVertexBuffer->SetPosition(9,  0.0, 1.0f, 0.0f);
    mVertexBuffer->SetPosition(10, 1.0, 1.0f, 0.0f);
    mVertexBuffer->SetPosition(11, 1.0, -1.0f, 0.0f);

    mVertexBuffer->Bind();
    mShader->Bind(identity, identity, identity);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 12);
    mVertexBuffer->Unbind();
}
