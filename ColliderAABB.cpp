#include "ColliderAABB.h"

ColliderAABB::ColliderAABB()
{

}

void ColliderAABB::SetColliderPosition(const QVector3D &ColliderPosition)
{
    mColliderPosition = ColliderPosition;
}

QVector3D ColliderAABB::GetColliderPosition() const
{
    return mColliderPosition;
}

void ColliderAABB::SetSize(QVector3D Size)
{
    mSize =Size;
}

QVector3D ColliderAABB::GetSize() const
{
    return mSize;
}
