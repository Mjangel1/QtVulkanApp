#ifndef NPCWITHBEZIER_H
#define NPCWITHBEZIER_H

#include "ObjMesh.h"
class NPCwithBEZIER : public ObjMesh
{
public:
    NPCwithBEZIER();

    void Tick(float Deltatime) override;

    void UpdateMatrix();

    void UpdateCollider();

private:

    QVector3D CurrentPos{0,0,0};

    float yPosition = 0;

    float mScale{1};


    float mSpeed = 1;

    float BezierT =0;
    float BezierDirection = 1;

    bool bFinishedpath = false;
    QVector2D Pos;


    bool bDetected = false;
    QVector3D Playerpos;

    bool bHasReseted =true;
    QVector2D PatrolStartpos;

    QVector3D d;


    //Collider
    ColliderAABB* ColliderAB;

public:

    QVector<QVector2D> PatrolPos;

    void SetPosition(const QVector3D &Position);
    QVector3D GetPosition();

    //Scale
    void scale(float s) override;
    float GetScale();


    void move(float x,float y,float z) override;

    void SetYPosition(float Y);


    QVector2D BezierCurve(float t,const QVector2D p0, const QVector2D p1, const QVector2D p2, const QVector2D p3);

    void IsDetected(bool bIsDetected, const QVector3D &PlayerPos) override;

    void ResetNPCPos();


};

#endif // NPCWITHBEZIER_H
