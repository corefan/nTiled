#version 440

// Input
// ----------------------------------------------------------------------------
layout (location = 0) in vec3 position;

// Variables
// ----------------------------------------------------------------------------
uniform float z_location;

// ----------------------------------------------------------------------------
//  Main
// ----------------------------------------------------------------------------
void main() { 
   	gl_Position = vec4(position.xy, z_location, 1.0f);
} 