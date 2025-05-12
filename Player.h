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


public:


    void SetPostion(const QVector3D &Position);
    QVector3D GetPosition();

    //Scale
    void scale(float s) override;
    float GetScale();

    void move(float x,float y,float z) override;

    void SetYPosition(float Y);


};

#endif // PLAYER_H
