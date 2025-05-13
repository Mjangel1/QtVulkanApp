#include "Surface.h"

Surface::Surface() : VisualObject()
{
    drawType = 1;
    CreateSurface();
}

void Surface::CreateSurface()
{

    //Create a TriangleSurface object that divides the area
   // [ -4.0,4.0]×[-3.0,3.0] into a regular triangulation with a spacing of 2.0 between vertices along each axis.
// Each vertex should have xyz-coordinates with a height of 0.0 and a normal.
  //you can choose whether the object lies in the xy-plane or xz-plane.

    for (int x = MinX; x < MaxX; x+=SpacX)
    {
        for (int z = MinZ; z < MaxZ; z+=SpacZ)
        {

            float x0 = x;
            float z0 = z;
            float x1 = x0+ SpacX;
            float z1 = z0+SpacZ;


            //triangle 1
            Vertex v1{x0,   0.0f,  z0,   0.0f, 0.0f, 1.0f, 1.0f, 0.0f};
            Vertex v2{x1,   0.0f,  z0,   0.0f, 0.0f, 1.0f, 1.0f, 0.0f};
            Vertex v3{x0,   0.0f,  z1,   0.0f, 0.0f, 1.0f, 1.0f, 0.0f};

            //triangle 2
            Vertex v4{x0,   0.0f,  z1,   0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
            Vertex v5{x1,   0.0f,  z0,   0.0f, 0.0f, 1.0f, 0.0f, 0.0f};
            Vertex v6{x1,   0.0f,  z1,   0.0f, 0.0f, 1.0f, 0.0f, 0.0f};

            mVertices.push_back(v1);
            mVertices.push_back(v2);
            mVertices.push_back(v3);
            mVertices.push_back(v4);
            mVertices.push_back(v5);
            mVertices.push_back(v6);

        }
    }

}
