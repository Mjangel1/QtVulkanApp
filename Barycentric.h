#ifndef BARYCENTRIC_H
#define BARYCENTRIC_H
#include "HeightMap.h"



    float getPositionInTerrain(HeightMap* Terrain,float Positionx,float PositionZ);

    QVector3D BarycentricCoordinetes(QVector2D ObjPos, QVector2D p0, QVector2D p1, QVector2D p2);

    bool IsObjectInsideTheTriangle(QVector3D bary);


#endif // BARYCENTRIC_H
