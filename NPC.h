#ifndef NPC_H
#define NPC_H

#include "ObjMesh.h"

class NPC : public ObjMesh
{
public:
    NPC();

    void Tick(float Deltatime) override;

    void UpdateMatrix();

private:

   QVector3D CurrentPos{0,0,0};

    float yPosition = 0;

   float mScale{1};

   int T = 0;
   float mSpeed = 1;

   bool bDetected = false;



public:

    QVector<QVector2D> PatrolPos;

    void SetPosition(const QVector3D &Position);
    QVector3D GetPosition();

    //Scale
    void scale(float s) override;
    float GetScale();


    void move(float x,float y,float z) override;

    void SetYPosition(float Y);

    //Patrol
    void Patrol (const QVector2D &Positions);








};

#endif // NPC_H
