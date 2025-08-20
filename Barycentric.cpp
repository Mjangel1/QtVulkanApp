#include "Barycentric.h"


//Float x and float Z is the position of the object you trying to
//calculta the Y value in relation to the HeightMap

bool FindObjectInTerrain(HeightMap *terrain, QVector2D pos, QVector3D &baryOut, Vertex &v0, Vertex &v1, Vertex &v2)
{
    const auto& indices = terrain->getIndices();
    const auto& vertices = terrain->getVertices();

    QVector2D ObjPos = pos;

    qDebug() << indices;

    for(size_t i = 0; i+2 < indices.size(); i+=3)
    {
        int index0 = indices.at(i);
        int index1 = indices.at(i+1);
        int index2 = indices.at(i+2);


        if (index0 >= vertices.size() || index1 >= vertices.size() || index2 >= vertices.size())
        {
            continue; // skip this triangle
        }

        //setting the vertices in the function to have values
        v0 = vertices[index0];
        v1 = vertices[index1];
        v2 = vertices[index2];



        QVector2D a(v0.x, v0.z);
        QVector2D b(v1.x, v1.z);
        QVector2D c(v2.x, v2.z);

        // qDebug() << "V0.y:" << V0.y << "V1.y:" << V1.y << "V2.y:" << V2.y;

        QVector3D bary = BarycentricCoordinetes(ObjPos,a,b,c);

        //setting what baryOut
        baryOut= bary;


        //qDebug() << bary.x() + bary.y() + bary.z() << " should be 1";

        if (IsObjectInsideTheTriangle(bary))
        {

            return true;

        }


    }

    return false;

}
float getPositionInTerrain(HeightMap *Terrain, float Positionx, float PositionZ)
{

    QVector2D ObjPos(Positionx, PositionZ);

    QVector3D bary;

    Vertex V0;
    Vertex V1;
    Vertex V2;

    //THE offset it so that the object does not clip throught the terrain.
    float offset = 0.5f;

    if(FindObjectInTerrain(Terrain,ObjPos,bary,V0,V1,V2))
    {
        float height = (bary.x() * V0.y) + (bary.y() * V1.y) + (bary.z() * V2.y);
        return height + offset;

        qDebug()<<height;

    }


    return -1.0;
}

QVector3D BarycentricCoordinetes(QVector2D ObjPos, QVector2D p0, QVector2D p1, QVector2D p2)
{
    //getting the edges
    QVector2D p10 = p1-p0;
    QVector2D p11 = p2-p0;

    //Location where the object is related to triangle
    QVector2D p12 = ObjPos-p0;

    // vector projection math
    float d00 = QVector2D::dotProduct(p10,p10);
    float d01 = QVector2D::dotProduct(p10,p11);
    float d11 = QVector2D::dotProduct(p11,p11);
    float d20 = QVector2D::dotProduct(p12,p10);
    float d21 = QVector2D::dotProduct(p12,p11);


    float denom = 1.0f / (d00 * d11 - d01 * d01);


    float v = (d11 * d20 - d01 * d21) * denom;
    float w = (d00 * d21 - d01 * d20) * denom;
    float u = 1.0f - v - w;

    return QVector3D(u, v, w);
}




bool IsObjectInsideTheTriangle(QVector3D bary)
{
    //checks if it's inside a triangle
    if (bary.x() >= 0.0f && bary.y() >= 0.0f && bary.z() >= 0.0f &&
        bary.x() <= 1.0f && bary.y() <= 1.0f && bary.z() <= 1.0f)
    {
        return true;
    }
    else
    {
        return false;
    }
}



bool IsObjectInsideTheTriangle(HeightMap *Terrain, float Positionx, float PositionZ)
{
    //function use to find out if player is inside or outside the actual HeightMap and returns if its true or not
    QVector2D ObjPos(Positionx, PositionZ);
    QVector3D bary;
    Vertex v0, v1, v2;
    bool bIsInside = FindObjectInTerrain(Terrain,ObjPos,bary,v0,v1,v2);

    return bIsInside;

}




