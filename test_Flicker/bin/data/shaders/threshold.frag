#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

uniform sampler2DRect diffuseTexture;
uniform float scale;
uniform float thresh;


varying vec2 texCoord;

void main() {
    //Getting coordinates of the current pixel in texture
    vec2 pos = texCoord;

    vec4 color = texture2DRect(diffuseTexture, pos);
	float b = (color.r + color.g + color.b) / 3.0;
	if (b < thresh) {
		color = vec4(0.0, 0.0, 0.0, 1.0);
	}
	else {
		color = vec4(1.0, 1.0, 1.0, 1.0);
	}

    gl_FragColor = color;
}
