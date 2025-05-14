#include "spherecollider.h"

SphereCollider::SphereCollider()
{

}

void SphereCollider::SetColliderPosition(QVector3D ColliderPosition)
{
    mColliderPosition = ColliderPosition;
}

QVector3D SphereCollider::GetColliderPosition() const
{
    return mColliderPosition;
}

void SphereCollider::SetRadius(float radius)
{
    Radius = radius;
}
