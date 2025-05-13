#ifndef PLAYER_H
#define PLAYER_H


#include "ObjMesh.h"


class Player : public ObjMesh
{
public:
    Player();

    void Tick(float Deltatime) override;

    void UpdateMatrix();


private:

    QVector3D CurrentPos{0,0,0};
    QVector3D Direction;
    float mSpeed;
    float mScale;
    float y = 0;

    float mScaleX;
    float mScaleY;


public:


    void SetPostion(const QVector3D &Position);
    QVector3D GetPosition();

    //Scale overall
    void scale(float s) override;
    float GetScale();

    //Scale only x and Y
    void ScaleXY(float x, float y) override;


    void move(float x,float y,float z) override;

    void SetYPosition(float Y);


};

#endif // PLAYER_H
