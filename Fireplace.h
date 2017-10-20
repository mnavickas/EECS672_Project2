// Fireplace.h

#ifndef Fireplace_H
#define Fireplace_H

#include <GL/gl.h>

#include "ObjTypes/MyContainer.h"
#include "ShaderIF.h"
#include <vector>

class Fireplace : public MyContainer
{
public:
	Fireplace(	ShaderIF* shaderIF,
            float dx = 0,
            float dy = 0,
            float dz = 0
			);

private:
    ShaderIF* shaderIF;
};

#endif
