// Cylinder.h

#ifndef CYLINDER_H
#define CYLINDER_H

#include <GL/gl.h>

#include "ObjTypes/MyView.h"
#include "ShaderIF.h"
#include "AffPoint.h"
#include "AffVector.h"

class Cylinder : public MyView
{
public:
    Cylinder(ShaderIF* sIF, double h, double r, double x, double y, double z, double thetaX, double thetaY,double thetaZ);
    virtual ~Cylinder();

    // xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
    void getMCBoundingBox(double* xyzLimits) const;
    bool handleCommand(unsigned char anASCIIChar, double ldsX, double ldsY);
    void render();

private:
    double minX,maxX,minY,maxY,minZ,maxZ;
    ShaderIF* shaderIF;
    GLuint vao[1];
    GLuint vbo[2]; // 0: coordinates; 1: normal vectors
    GLuint ebo[2];

    const cryph::AffPoint shift;

    cryph::AffVector topNormal;
    cryph::AffVector botNormal;

    const double mScaleHeight;
    const double mScaleRadius;

    const double mRotateX;
    const double mRotateY;
    const double mRotateZ;
    static GLuint indices[2][20];

    void defineCylinder();
};

#endif
