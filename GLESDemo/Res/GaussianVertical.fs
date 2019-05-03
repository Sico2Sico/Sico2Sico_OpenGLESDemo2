#ifdef GL_ES
precision mediump float;
#endif
varying vec2 V_Texcoord;
uniform sampler2D U_Texture;
void main()
{
	float texelOffset=1.0/200.0;
	float weight[5];
	weight[0]=0.22;
	weight[1]=0.19;
	weight[2]=0.12;
	weight[3]=0.08;
	weight[4]=0.01;
	vec4 color=texture2D(U_Texture,V_Texcoord)*weight[0];
	for(int i=1;i<5;i++)
	{
		color+=texture2D(U_Texture,vec2(V_Texcoord.x,V_Texcoord.y+texelOffset*float(i)))*weight[i];
		color+=texture2D(U_Texture,vec2(V_Texcoord.x,V_Texcoord.y-texelOffset*float(i)))*weight[i];
	}
	gl_FragColor=color;
}