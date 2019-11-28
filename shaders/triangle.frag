#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(binding = 1) uniform sampler2D texSampler;
layout(location = 0) in vec4 fragColor;
layout(location = 1) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;
/*
void main() {
    outColor = texture(texSampler, fragTexCoord);
}

void main() {
    outColor = texture(texSampler, fragTexCoord * 2.0);
}
*/
void main() {
	if(texture(texSampler, fragTexCoord).a < 1.0){
		discard;
	}
    outColor = vec4(fragColor.rgb * texture(texSampler, fragTexCoord).rgb, 0.5);
	/*outColor = texture(texSampler, fragTexCoord);*/
}
