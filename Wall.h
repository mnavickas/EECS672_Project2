// Wall.h

#ifndef Wall_H
#define Wall_H

#include <GL/gl.h>

#include "ObjTypes/MyView.h"
#include "ShaderIF.h"

class Wall : public MyView
{
public:
	Wall(ShaderIF* sIF, float dx, float dy, float dz);
	virtual ~Wall();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimits) const;
	bool handleCommand(unsigned char anASCIIChar, double ldsX, double ldsY);
	void render();
private:
	ShaderIF* shaderIF;
	GLuint vao[1];
	GLuint vbo[1];

	float xmin, xmax, ymin, ymax, zmin, zmax;

	float dx, dy, dz;
	static GLuint indexList[4][7];

	void defineWall();
	void renderWall();
};

#endif
