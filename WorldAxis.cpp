#include "WorldAxis.h"

WorldAxis::WorldAxis()
{
    drawType = 2; // 0 = fill with texture, 1 = fill, 2= lines

	mVertices.push_back(Vertex{ -100.f, 0.f, 0.f,       1.f, 0.f, 0.f,    0.f, 0.f }); //x-axis
    mVertices.push_back(Vertex{ 100.f, 0.f, 0.f,     1.f, 0.f, 0.f,    0.f, 0.f });
	mVertices.push_back(Vertex{ 0.f, -100.f, 0.f,       0.f, 1.f, 0.f,    0.f, 0.f }); //y-axis
    mVertices.push_back(Vertex{ 0.f, 100.f, 0.f,     0.f, 1.f, 0.f,    0.f, 0.f });
	mVertices.push_back(Vertex{ 0.f, 0.f, -100.f,       0.f, 0.f, 1.f,    0.f, 0.f }); //z-axis
    mVertices.push_back(Vertex{ 0.f, 0.f, 100.f,     0.f, 0.f, 1.f,    0.f, 0.f });

    mMatrix.setToIdentity();
}

