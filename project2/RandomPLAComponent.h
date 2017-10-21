// RandomPLAComponent.h

#ifndef RandomPLAComponent_H
#define RandomPLAComponent_H

#include "ObjTypes/MyView.h"

class RandomPLAComponent : public MyView
{
public:
    RandomPLAComponent
    (
        ShaderIF* sIF,
        double x = 0,
        double y = 0,
        double z = 0,
        int count = 3
    );

    ~RandomPLAComponent();

    // xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
    void getMCBoundingBox(double* xyzLimits) const;
    bool handleCommand(unsigned char anASCIIChar, double ldsX, double ldsY);
    void render();
    virtual void rotate( const cryph::AffPoint& point, const cryph::AffVector& vector, float degrees ){}

private:
    double minX,maxX,minY,maxY,minZ,maxZ;
    GLuint vao[1];
    GLuint vbo[3]; // 0: coordinates; 1: kd; 2:ka
    int count;
    const cryph::AffPoint shift;

    cryph::AffVector topNormal;


    void defineRandomPLAComponent();
};

#endif
