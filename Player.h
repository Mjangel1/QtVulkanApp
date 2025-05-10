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
    float mSpeed;
    float mScale;

public:


    void SetPostion(const QVector3D &Position);
    QVector3D GetPosition();

    void scale(float s) override;
    float GetScale();

    void move(float x,float y,float z) override;

    //Scale


};

#endif // PLAYER_H
