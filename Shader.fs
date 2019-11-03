#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
in vec3 Normal;
in vec3 FragPos;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform vec3 lightColor; 
uniform vec3 lightPos;

void main()
{
   // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;
            
    // vec3 result = (ambient + diffuse);
    // linearly interpolate between both textures (80% container, 20% awesomeface)
	FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.5f) * vec4(diffuse,1.0f);
    // FragColor = texture(texture1, TexCoord) ;
    // FragColor = vec4(lightColor,1.0f);
}