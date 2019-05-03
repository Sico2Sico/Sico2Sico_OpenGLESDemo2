#ifdef GL_ES
precision mediump float;
#endif
varying vec2 V_Texcoord;
uniform sampler2D U_Texture;
void main()
{
//    float texelOffset=1.0/200.0;
//    float weight[5];
//    weight[0]=0.22;
//    weight[1]=0.19;
//    weight[2]=0.12;
//    weight[3]=0.08;
//    weight[4]=0.01;
//    vec4 color=texture2D(U_Texture,V_Texcoord)*weight[0];
//    for(int i=1;i<5;i++)
//    {
//        color+=texture2D(U_Texture,vec2(V_Texcoord.x+texelOffset*float(i),V_Texcoord.y))*weight[i];
//        color+=texture2D(U_Texture,vec2(V_Texcoord.x-texelOffset*float(i),V_Texcoord.y))*weight[i];
//    }
//    gl_FragColor=color;
    vec4 color=vec4(0.0);
    int coreSize=3;
    float texelOffset=1.0/300.0;
    float kernel[9];
    kernel[6]=0.0;kernel[7]=1.0;kernel[8]=0.0;
    kernel[3]=1.0;kernel[4]=-4.0;kernel[5]=1.0;
    kernel[0]=0.0;kernel[1]=1.0;kernel[2]=0.0;
    int index=0;
    for(int y=0;y<coreSize;y++)
    {
        for(int x=0;x<coreSize;x++)
        {
            vec4 currentColor=texture2D(U_Texture,V_Texcoord+vec2(float(-1+x)*texelOffset,float(-1+y)*texelOffset));
            color+=currentColor*kernel[index++];
        }
    }
    gl_FragColor=4.0*color+texture2D(U_Texture,V_Texcoord);
}
