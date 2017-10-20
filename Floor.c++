// Floor.c++

#include <iostream>
#include <math.h>

#include "Floor.h"

Floor::Floor(ShaderIF* sIF) :
	shaderIF(sIF)
{
	xmin = -15;
    xmax = 70;


    ymax = -4;
	ymin = ymax-0.1;

    zmin = -50;
    zmax = 30;

    kd[0] = 0.4; kd[1] = 0.4; kd[2] = 0.4;
    ka[0] = 0.4; ka[1] = 0.4; ka[2] = 0.4;
	defineFloor();
}

Floor::~Floor()
{
	glDeleteBuffers(1, vbo);
	glDeleteVertexArrays(1, vao);
}

void Floor::defineFloor()
{
	vec3 vtx[] = { // The 8 unique vertices (Note the order)
		{xmin, ymax, zmax},
		{xmax, ymax, zmax},
		{xmin, ymax, zmin},
		{xmax, ymax, zmin}
	};

	glGenVertexArrays(1, vao);
	glBindVertexArray(vao[0]);

	glGenBuffers(1, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, 4*sizeof(vec3), vtx, GL_STATIC_DRAW);
	glVertexAttribPointer(shaderIF->pvaLoc("mcPosition"), 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(shaderIF->pvaLoc("mcPosition"));

	glDisableVertexAttribArray(shaderIF->pvaLoc("mcNormal"));
}

// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
void Floor::getMCBoundingBox(double* xyzLimits) const
{
	xyzLimits[0] = xmin;
	xyzLimits[1] = xmax;
	xyzLimits[2] = ymin;
	xyzLimits[3] = ymax;
	xyzLimits[4] = zmin;
	xyzLimits[5] = zmax;
}

bool Floor::handleCommand(unsigned char anASCIIChar, double ldsX, double ldsY)
{
	// Floor does not look for events; just hand off to inherited handleCommand.
	return this->ModelView::handleCommand(anASCIIChar, ldsX, ldsY);
}

void Floor::renderFloor()
{
	glBindVertexArray(vao[0]);

	glVertexAttrib3f(shaderIF->pvaLoc("mcNormal"), 0.0, 1.0, 0.0);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void Floor::render()
{
	GLint pgm;
	glGetIntegerv(GL_CURRENT_PROGRAM, &pgm);
	glUseProgram(shaderIF->getShaderPgmID());

	cryph::Matrix4x4 mc_ec, ec_lds;
	getMatrices(mc_ec, ec_lds);
	float mat[16];
	glUniformMatrix4fv(shaderIF->ppuLoc("mc_ec"), 1, false, mc_ec.extractColMajor(mat));
	glUniformMatrix4fv(shaderIF->ppuLoc("ec_lds"), 1, false, ec_lds.extractColMajor(mat));
	glUniform3fv(shaderIF->ppuLoc("kd"), 1, kd);
	glUniform3fv(shaderIF->ppuLoc("ka"), 1, ka);
	renderFloor();

	glUseProgram(pgm);
}
