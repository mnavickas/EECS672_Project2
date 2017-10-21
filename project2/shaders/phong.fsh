#version 410 core

// phong.fsh - a fragment shader that implements a Phong Lighting model.


in PVA
{
	vec3 ecPosition;
	vec3 ecUnitNormal;
} pvaIn;

out vec4 fragmentColor;

uniform vec3 kd = vec3(0.8, 0.0, 0.0); //default
uniform vec3 ka = vec3(0.5, 0.5, 0.5); //default

vec3 globalAmbient = vec3(0.1, 0.1, 0.1);
vec3 lightStrength = vec3(0.9, 0.9, 0.9);

vec4 p_ecLightSourcePos = vec4( 0.1,0,1,0); //directional light source

uniform int usePVAcolor = 0;
in vec3 colorToFS;

vec4 evaluateLightingModel()
{
	vec3 ambient = ka;
	vec3 diffuse = kd;
	if( usePVAcolor == 1)
	{
		diffuse = colorToFS;
		ambient = colorToFS;
	}

	vec3 ambientPart = ambient * globalAmbient;


	vec3 liHat;
	if( p_ecLightSourcePos.w == 0 )
	{
		// directional
		liHat = normalize(p_ecLightSourcePos.xyz);
	}
	else
	{
		// positional
		liHat = normalize( p_ecLightSourcePos.xyz-pvaIn.ecPosition );
	}

	vec3 norm = pvaIn.ecUnitNormal;


	vec3 diffusePart;
	if( dot(norm, p_ecLightSourcePos.xyz) >= 0 ) // only light it if it is on the same side.
	{
		diffusePart = lightStrength * diffuse * dot(normalize( norm ),liHat);
	}
	else
	{
		diffusePart = vec3(0,0,0);
	}

	return vec4( ambientPart + diffusePart, 1.0);
}

void main ()
{
	fragmentColor = evaluateLightingModel();
}
