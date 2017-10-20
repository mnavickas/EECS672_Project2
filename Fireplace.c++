// Fireplace.c++

#include <iostream>
#include <math.h>
#include "Cylinder.h"
#include "RectangularPrism.h"
#include "Wall.h"
#include "Fireplace.h"

static int fcount = 0;
Fireplace::Fireplace(ShaderIF* sIF, float dx, float dy, float dz) :
	shaderIF(sIF)
{

	int layers = 3;
	int count = 24*layers;
	vec3 cylinderCenters[count];
	float cylinderOrientation[count];


	float openRadius = 10;



	float dTheta = M_PI/(count/layers);


	float i = 0.0;
	for(int index = 0; index<count; i+=dTheta)
	{
		for(int j = 0; j < layers; j++, index++)
		{
			cylinderCenters[index][0] = dx+3*j-5.5;
			cylinderCenters[index][1] = openRadius*sin(i) + dy -3;
			cylinderCenters[index][2] = openRadius*cos(i) + dz;
			cylinderOrientation[index] = 90+(180.0/M_PI*cos(i));
		}
	}

	for(int i = 0;i< count; i++)
	{
		Cylinder* c = new Cylinder(sIF,2.5,2,	cylinderCenters[i][0],cylinderCenters[i][1],cylinderCenters[i][2], cylinderOrientation[i],0,0 );
		c->setKa(0.05,0.05,0.05);
		c->setKd(0.3,0.15,0.2);
		addComponent( c );
	}

	//logs
	Cylinder* c1 = new Cylinder(sIF,5,1,	dx-4,dy,dz, 90,30,0 );
	Cylinder* c2 = new Cylinder(sIF,5.5,1.2,	dx-4.2,dy-0.1,dz+1.5, 90,-30,45 );
	if( fcount++ %2 == 0)
	{

		c1->setKa(184.0/255,131.0/255,11.0/255);
		c1->setKd(184.0/255,131.0/255,11.0/255);
		c2->setKa(130.0/255,81.0/255,1.0/255);
		c2->setKd(130.0/255,81.0/255,1.0/255);
	}
	else
	{
		c2->setKa(184.0/255,131.0/255,11.0/255);
		c2->setKd(184.0/255,131.0/255,11.0/255);
		c1->setKa(130.0/255,81.0/255,1.0/255);
		c1->setKd(130.0/255,81.0/255,1.0/255);
	}
	addComponent( c1 );
	addComponent( c2 );

	//floor
	RectangularPrism* floorPanel = new RectangularPrism(sIF,16,2,27,dx-3,dy-3,dz);
	floorPanel->setKa(0.7,0.05,0.05);
	floorPanel->setKd(90.0/255,4.0/255,27/255);
	addComponent( floorPanel );

	RectangularPrism* backPanel = new RectangularPrism(sIF,1,20,27,dx+1.5,dy+10-3,dz);
	backPanel->setKa(0.7,0.05,0.05);
	backPanel->setKd(90.0/255,4.0/255,27/255);

	//back wall
	addComponent( backPanel );

	RectangularPrism* chimney = new RectangularPrism(sIF,10,42,10,	dx+3.8,dy+26,dz);
	chimney->setKa(0.7,0.05,0.05);
	chimney->setKd(90.0/255,4.0/255,27/255);

	//back wall
	addComponent( chimney );

	Wall* wall = new Wall(sIF,dx,dy,dz);
	wall->setKd(0.8,0.8,0.8);
	wall->setKd(1,1,1);
	addComponent( wall );


}
