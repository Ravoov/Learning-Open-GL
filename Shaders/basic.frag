#version 330 core

in vec2 TexCoord; // This will receive your interpolated UV coordinates

out vec4 FragColor;

uniform sampler2D u_Texture; // Still declare, but not used for this test

void main() {
    // Visualize texture coordinates as colors:
    // TexCoord.x (U) maps to Red, TexCoord.y (V) maps to Green.
    // We add 0.0 for Blue and 1.0 for Alpha (fully opaque).
    FragColor = texture(u_Texture, TexCoord);
}
