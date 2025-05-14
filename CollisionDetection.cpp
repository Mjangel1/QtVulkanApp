#include "CollisionDetection.h"


bool CheckCollisionAABBOnly(ColliderAABB &Actor, ColliderAABB &OtherActor)
{

    if(Actor.GetColliderPosition().x() - Actor.GetSize().x() <=OtherActor.GetColliderPosition().x() + OtherActor.GetSize().x()
        && Actor.GetColliderPosition().x() + Actor.GetSize().x() >= OtherActor.GetColliderPosition().x() - OtherActor.GetSize().x()
        && Actor.GetColliderPosition().y() - Actor.GetSize().y() <= OtherActor.GetColliderPosition().y() + OtherActor.GetSize().y()
        && Actor.GetColliderPosition().y() + Actor.GetSize().x() >= OtherActor.GetColliderPosition().y() - OtherActor.GetSize().y()
        && Actor.GetColliderPosition().z() - Actor.GetSize().z() <= OtherActor.GetColliderPosition().z() + OtherActor.GetSize().z()
        && Actor.GetColliderPosition().z() + Actor.GetSize().z() >= OtherActor.GetColliderPosition().z() - OtherActor.GetSize().z())
    {
        return true;

    }
    else{ return false;}

}

bool CheckSphereCollision(SphereCollider &Actor, SphereCollider &OtherActor)
{
    float distance = (Actor.GetColliderPosition()-OtherActor.GetColliderPosition()).length();

// if the distance between the center of each sphere is smaller or equal to the sum of both radius its colliding
    if(distance <= Actor.GetRadius()+ OtherActor.GetRadius())
    {
        return true;
    }
    return false;

}

bool CheckAabbSphereCollision(ColliderAABB &Actor, SphereCollider &OtherActor)
{

    QVector3D MinAABB= Actor.GetColliderPosition()- Actor.GetSize();
    QVector3D MaxAABB= Actor.GetColliderPosition()+ Actor.GetSize();


    float distance;

    return 0;

}
