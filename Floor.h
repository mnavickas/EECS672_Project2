// Floor.h

#ifndef Floor_H
#define Floor_H

#include <GL/gl.h>

#include "ObjTypes/MyView.h"
#include "ShaderIF.h"

class Floor : public MyView
{
public:
    Floor(ShaderIF* sIF);
    virtual ~Floor();

    // xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
    void getMCBoundingBox(double* xyzLimits) const;
    bool handleCommand(unsigned char anASCIIChar, double ldsX, double ldsY);
    void render();
private:
    ShaderIF* shaderIF;
    GLuint vao[1];
    GLuint vbo[1];

    float xmin, xmax, ymin, ymax, zmin, zmax;

    void defineFloor();
    void renderFloor();
};

#endif
