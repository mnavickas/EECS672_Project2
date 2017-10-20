// Table.c++

#include <iostream>
#include <math.h>
#include "Cylinder.h"
#include "RectangularPrism.h"

#include "Table.h"
#include <string.h>

Table::Table(ShaderIF* sIF, float dx, float dy, float dz, float height, float width, float length) :
	shaderIF(sIF)
{
    int tableWidth = 10*width;
    int tableLength =10*length;


    addComponent(new Cylinder(sIF,4*height,1, -(tableWidth/2 - tableWidth/8)+dx,  dy,   (tableLength/2 - tableLength/8)+dz,       0,0,0));
    addComponent(new Cylinder(sIF,4*height,1,  (tableWidth/2 - tableWidth/8)+dx,  dy,   (tableLength/2 - tableLength/8)+dz,       0,0,0));
    addComponent(new Cylinder(sIF,4*height,1, -(tableWidth/2 - tableWidth/8)+dx,  dy,  -(tableLength/2 - tableLength/8)+dz,       0,0,0));
    addComponent(new Cylinder(sIF,4*height,1,  (tableWidth/2 - tableWidth/8)+dx,  dy,  -(tableLength/2 - tableLength/8)+dz,       0,0,0));

    RectangularPrism* prism = new RectangularPrism(sIF,  10*width,1,10*length,  dx, dy+4*height, dz);
    prism->setKa(0.2125,0.1275,0.054);
    prism->setKd(0.714,0.4284,0.18144);
    addComponent( prism );
}
