// RandomPLAComponent.c++
#include "RandomPLAComponent.h"

#include "Matrix3x3.h"


RandomPLAComponent::RandomPLAComponent(ShaderIF* sIF, double x, double y, double z, int count)
    : MyView(sIF)
    , shift(x,y,z)
{
    this->count = count;
    defineRandomPLAComponent();
}

RandomPLAComponent::~RandomPLAComponent()
{
    glDeleteBuffers(1, vbo);
    glDeleteVertexArrays(1, vao);
}


const int N_POINTS_AROUND_SLICE = 18; // number points around a cross-section

void RandomPLAComponent::defineRandomPLAComponent()
{
    typedef float vec3[3];
    const int nPoints = 7;

    const float x = shift.x;
    const float y = shift.y;
    const float z = shift.z;
    vec3 coords[]
    {
        {0+x,8.6f+y,0+z},
        {5+x,0+y,0+z},
        {10+x,8.6f+y,0+z},
        {15+x,0+y,0+z},
        {20+x,8.6f+y,0+z},
        {25+x,0+y,0+z},
        {30+x,8.6f+y,0+z},
        {35+x,0+y,0+z}
    };

    vec3 colorcoords[]
    {
        {1,0,0},
        {0,1,0},
        {0,0,1},
        {1,0,0},
        {0,1,0},
        {0,0,1},
        {1,0,0},
        {0,1,0},
    };

    // ************************************************************************
    // EXERCISE: Create/fill VAOs and VBOs here.
    //           Also use glVertexAttribPointer and glEnableVertexAttribArray
    // ************************************************************************
    glGenVertexArrays(1,vao);
    glGenBuffers(2,vbo);
    glBindVertexArray(vao[0]);
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);

    glBufferData(GL_ARRAY_BUFFER, (nPoints)*sizeof(vec3), coords, GL_STATIC_DRAW);
    glVertexAttribPointer(shaderIF->pvaLoc("mcPosition"), 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(shaderIF->pvaLoc("mcPosition"));

    glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);

    glBufferData(GL_ARRAY_BUFFER, (nPoints)*sizeof(vec3), colorcoords, GL_STATIC_DRAW);
    glVertexAttribPointer(shaderIF->pvaLoc("vertexColor"), 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(shaderIF->pvaLoc("vertexColor"));




    glDisableVertexAttribArray(shaderIF->pvaLoc("mcNormal"));

}

// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
void RandomPLAComponent::getMCBoundingBox(double* xyzLimits) const
{
    xyzLimits[0] = minX;
    xyzLimits[1] = maxX;
    xyzLimits[2] = minY;
    xyzLimits[3] = maxY;
    xyzLimits[4] = minZ;
    xyzLimits[5] = maxZ;
}

bool RandomPLAComponent::handleCommand(unsigned char anASCIIChar, double ldsX, double ldsY)
{
    // RandomPLAComponent does not look for events. Just hand off back to inherited handleCommand.
    return this->ModelView::handleCommand(anASCIIChar, ldsX, ldsY);
}

void RandomPLAComponent::render()
{
    typedef float vec3[3];
    GLint pgm;
    glGetIntegerv(GL_CURRENT_PROGRAM, &pgm);
    glUseProgram(shaderIF->getShaderPgmID());

    cryph::Matrix4x4 mc_ec, ec_lds;
    getMatrices(mc_ec, ec_lds);
    float mat[16];
    glUniformMatrix4fv(shaderIF->ppuLoc("mc_ec"), 1, false, mc_ec.extractColMajor(mat));
    glUniformMatrix4fv(shaderIF->ppuLoc("ec_lds"), 1, false, ec_lds.extractColMajor(mat));


    glBindVertexArray(vao[0]);
    glUniform1i(shaderIF->ppuLoc("usePVAcolor"), 1);


    for(int i = 0; i < count; i++)
        glDrawArrays(GL_TRIANGLES, 2*i, 3);



    glUniform1i(shaderIF->ppuLoc("usePVAcolor"), 0);
    glUseProgram(pgm);
}
