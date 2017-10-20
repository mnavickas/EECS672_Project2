// Bed.h

#ifndef Bed_H
#define Bed_H

#include "ObjTypes/MyContainer.h"
#include "ShaderIF.h"

class Bed : public MyContainer
{
public:
	Bed(	ShaderIF* shaderIF,
            float dx = 0,
            float dy = 0,
            float dz = 0
        );
private:
    ShaderIF* shaderIF;

};

#endif
