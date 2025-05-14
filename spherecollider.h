#ifndef SPHERECOLLIDER_H
#define SPHERECOLLIDER_H

#include <qvectornd.h>
class SphereCollider
{
public:
    SphereCollider();


private:

    QVector3D mColliderPosition;
    float Radius {0.0f};

public:


    void SetColliderPosition(QVector3D ColliderPosition);

    QVector3D GetColliderPosition() const;

    void SetRadius(float radius);
    float GetRadius();



};

#endif // SPHERECOLLIDER_H
