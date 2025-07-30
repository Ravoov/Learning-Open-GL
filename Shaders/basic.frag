#version 330 core

in vec2 TexCoord; // This will receive your interpolated UV coordinates

out vec4 FragColor;

uniform sampler2D u_Texture; // Still declare, but not used for this test

void main() {
    // Visualize texture coordinates as colors:
    // TexCoord.x (U) maps to Red, TexCoord.y (V) maps to Green.
    // This will create a gradient if your UVs are working.
    FragColor = vec2(TexCoord.x, TexCoord.y);
}