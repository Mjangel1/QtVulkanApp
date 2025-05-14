#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H
#include "ColliderAABB.h"
#include "spherecollider.h"


bool CheckCollisionAABBOnly(ColliderAABB &Actor,ColliderAABB &OtherActor);

bool CheckSphereCollision(SphereCollider &Actor,SphereCollider &OtherActor);

bool CheckAabbSphereCollision(ColliderAABB &Actor,SphereCollider &OtherActor);

#endif // COLLISIONDETECTION_H
