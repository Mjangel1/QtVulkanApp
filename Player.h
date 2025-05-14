#ifndef PLAYER_H
#define PLAYER_H


#include "ObjMesh.h"
#include "ColliderAABB.h"


class Player : public ObjMesh
{
public:
    Player();

    void Tick(float Deltatime) override;

    void UpdateMatrix();


private:

    QVector3D CurrentPos{0,0,0};
    QVector3D Direction;

    QVector3D LastPosition;



    float mSpeed;
    float mScale;
    float y = 0;

    float mScaleX;
    float mScaleY;


    bool bInsideMap = true;



public:

    QVector3D NextPosition;
    void SetPostion(const QVector3D &Position);
    QVector3D GetPosition();

    //Scale overall
    void scale(float s) override;
    float GetScale();

    //Scale only x and Y
    void ScaleXY(float x, float y) override;


    void move(float x,float y,float z) override;

    void SetYPosition(float Y);

    void OutsideBoundry();

    bool getIsInsideMap(bool IsInside);


};

#endif // PLAYER_H
