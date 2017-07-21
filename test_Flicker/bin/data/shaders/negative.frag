#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

uniform sampler2DRect diffuseTexture;
uniform float scale;

varying vec2 texCoord;

void main() {
    //Getting coordinates of the current pixel in texture
    vec2 pos = texCoord;
        
    vec4 color = texture2DRect(diffuseTexture, pos / scale);
	color.rgb = vec3(1.0) - color.rgb;
    gl_FragColor = color;
}
