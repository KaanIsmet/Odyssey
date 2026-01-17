#version 330 core

in vec2 TexCoord;
out vec4 FragColor;

uniform sampler2D spriteTexture;
uniform vec4 spriteColor; // Tint color

void main() {
    vec4 texColor = texture(spriteTexture, TexCoord);
    FragColor = texColor * spriteColor;
}