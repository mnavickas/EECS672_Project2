// Floor.h

#ifndef Floor_H
#define Floor_H

#include "ObjTypes/MyView.h"

class Floor : public MyView
{
public:
    Floor
    (
        ShaderIF* sIF
    );
    ~Floor();

    // xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
    void getMCBoundingBox(double* xyzLimits) const;
    bool handleCommand(unsigned char anASCIIChar, double ldsX, double ldsY);
    void render();
    virtual void rotate( const cryph::AffPoint& point, const cryph::AffVector& vector, float degrees ){};
private:
    GLuint vao[1];
    GLuint vbo[1];

    float xmin, xmax, ymin, ymax, zmin, zmax;

    void defineFloor();
    void renderFloor();
};

#endif
