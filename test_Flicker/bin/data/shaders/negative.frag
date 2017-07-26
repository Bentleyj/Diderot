#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

uniform sampler2DRect diffuseTexture;
uniform float scale;
uniform float thresh;
uniform float negative;

varying vec2 texCoord;

void main() {
    //Getting coordinates of the current pixel in texture
    vec2 pos = texCoord;
        
    vec4 color = texture2DRect(diffuseTexture, pos / scale);
	color.rgb = vec3(negative) - (2 * negative - 1) * color.rgb;

	if (thresh > 0) {
		float b = (color.r + color.g + color.b) / 3.0;

		if (b < thresh) {
			color = vec4(0.0, 0.0, 0.0, 1.0);
		}
		else {
			color = vec4(1.0, 1.0, 1.0, 1.0);
		}
	}

    gl_FragColor = color;
}
