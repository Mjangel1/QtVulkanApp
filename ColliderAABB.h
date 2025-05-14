#ifndef COLLIDERAABB_H
#define COLLIDERAABB_H

#include <qvectornd.h>
class ColliderAABB
{
public:
    ColliderAABB();

private:

    //location of the colllider
    QVector3D mColliderPosition;
    //size of the collider
    QVector3D mSize;


public:

    void SetColliderPosition(const QVector3D &ColliderPosition);

    QVector3D GetColliderPosition() const;

    void SetSize(QVector3D Size);

    QVector3D GetSize() const;


};

#endif // COLLIDERAABB_H
