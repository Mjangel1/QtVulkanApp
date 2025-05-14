#include "VisualObject.h"
#include "ColliderAABB.h"

VisualObject::VisualObject()
{
    mMatrix.setToIdentity();
}

void VisualObject::move(float x, float y, float z)
{
    mMatrix.translate(x, y, z);
}

void VisualObject::scale(float s)
{
    mMatrix.scale(s);

}

void VisualObject::ScaleXY(float x, float y)
{
    mMatrix.scale(x,y);
}

void VisualObject::rotate(float t, float x, float y, float z)
{
    mMatrix.rotate(t, x, y, z);
}

QVector3D VisualObject::getPosition()
{
    float x = mMatrix(0, 3); // Position in the x-axis
    float y = mMatrix(1, 3); // Position in the y-axis
    float z = mMatrix(2, 3); // Position in the z-axis
    return QVector3D(x, y, z);
}

void VisualObject::setPosition(float x, float y, float z)
{
    mMatrix(0, 3) = x; // Position in the x-axis
    mMatrix(1, 3) = y; // Position in the y-axis
    mMatrix(2, 3) = z; // Position in the z-axis
}

void VisualObject::Tick(float Deltatime)
{

}

void VisualObject::IsDetected(bool bIsDetected, const QVector3D &PlayerPos)
{

}

void VisualObject::SetColliderAABB(ColliderAABB *colliderAABB)
{
    if(colliderAABB == nullptr)
    {
        qDebug() << "Collider pointer is null!";
        return; // Do not assign if nullptr
    }

    ColliderAB =colliderAABB;
}

ColliderAABB &VisualObject::GetColliderAABB()
{
    if(!ColliderAB)
    {
        qDebug() << "Collider not found!";

    }


    return *ColliderAB;
}












