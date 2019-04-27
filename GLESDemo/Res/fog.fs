#ifdef GL_ES
precision mediump float;
#endif
uniform vec4 U_CameraPos;
uniform vec4 U_FogOption;
uniform vec4 U_FogColor;
varying vec4 V_Color;
varying vec4 V_EyeSpacePos;

/// ap 系数
float CalculateLinearFog(float distance)
{
	float fogAlpha=(distance-U_FogOption.x)/(U_FogOption.y-U_FogOption.x);
	fogAlpha=1.0-clamp(fogAlpha,0.0,1.0);
	return fogAlpha;
}
void main()
{
	float fogAlpha=CalculateLinearFog(abs(V_EyeSpacePos.z/V_EyeSpacePos.w));
	gl_FragColor=mix(U_FogColor,V_Color,fogAlpha);
}
