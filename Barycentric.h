#ifndef BARYCENTRIC_H
#define BARYCENTRIC_H
#include "HeightMap.h"





bool FindObjectInTerrain(HeightMap* terrain, QVector2D pos, QVector3D& baryOut, Vertex& v0, Vertex& v1, Vertex& v2);

    float getPositionInTerrain(HeightMap* Terrain,float Positionx,float PositionZ);

    QVector3D BarycentricCoordinetes(QVector2D ObjPos, QVector2D p0, QVector2D p1, QVector2D p2);

    bool IsObjectInsideTheTriangle(QVector3D bary);

    bool IsObjectInsideTheTriangle(HeightMap* Terrain,float Positionx,float PositionZ);







#endif // BARYCENTRIC_H
