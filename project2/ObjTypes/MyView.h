// Cylinder.h

#ifndef MyView_H
#define MyView_H

#include "ModelView.h"

#include <GL/gl.h>

#include "ShaderIF.h"
#include "AffPoint.h"
#include "AffVector.h"

//extend some basic functionallity across modelviews
class MyView : public ModelView
{

protected:
	typedef float vec3[3];
    float kd[3];
    float ka[3];
	ShaderIF* shaderIF;

public:
    virtual void setKd(float r, float g, float b)
    {
    	if(r <= 1 && r >= 0) kd[0] = r;
    	if(g <= 1 && g >= 0) kd[1] = g;
    	if(b <= 1 && b >= 0) kd[2] = b;
    }
    virtual void setKa(float r, float g, float b)
    {
    	if(r <= 1 && r >= 0) ka[0] = r;
    	if(g <= 1 && g >= 0) ka[1] = g;
    	if(b <= 1 && b >= 0) ka[2] = b;
    }
	MyView
	(
		ShaderIF* sIF
	)
	: shaderIF(sIF)
	{}

	virtual void rotate( const cryph::AffPoint& point, const cryph::AffVector& vector, float degrees ) = 0;
};

#endif
