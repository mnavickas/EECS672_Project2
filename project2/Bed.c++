// Bed.c++
#include "Bed.h"

#include "Cylinder.h"
#include "RectangularPrism.h"

Bed::Bed(ShaderIF* sIF, float dx, float dy, float dz) : MyContainer(sIF)
{
    //'pillow'
    Cylinder* cyl = new Cylinder(sIF,5.9,2,	-10+dx,6+dy,0+dz,	90,0,0);
    cyl->setKd(0.9,0.9,0.9);
    cyl->setKa(0.9,0.9,0.9);
    addComponent(cyl);

    //legs
    addComponent(new Cylinder(sIF,4,1,  -8+dx,0+dy, 4+dz,       0,270,0));
    addComponent(new Cylinder(sIF,4,1,   8+dx,0+dy, 4+dz,       0,270,0));
    addComponent(new Cylinder(sIF,4,1,  -8+dx,0+dy,-4+dz,       0,270,0));
    addComponent(new Cylinder(sIF,4,1,   8+dx,0+dy,-4+dz,       0,270,0));

    //mattress
    addComponent(new RectangularPrism(sIF,  24,4,12,  0+dx,4+dy,0+dz));
}
