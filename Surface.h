#ifndef SURFACE_H
#define SURFACE_H

#include "VisualObject.h"
class Surface : public VisualObject
{
public:
    Surface();

private:

    float MinX = -4.0f;
    float MaxX = 4.0f;
    float MinZ = -3.0f;
    float MaxZ = 3.0f;

    //spacing
    float SpacX = 2.0f;
    float SpacZ = 2.0f;

public:

    void CreateSurface();


};

#endif // SURFACE_H
