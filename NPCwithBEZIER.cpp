#include "NPCwithBEZIER.h"

NPCwithBEZIER::NPCwithBEZIER() : ObjMesh(assetPath + "cube.obj")
{
    PatrolPos.push_back(QVector2D(-2.5,-2.0));
    PatrolPos.push_back(QVector2D(1.0,0.50));
    PatrolPos.push_back(QVector2D(-1.5,1.0));
    PatrolPos.push_back(QVector2D(1.5,2.5));

    setName("NPC");

    PatrolStartpos = PatrolPos.at(0);

    SetPosition(QVector3D(PatrolPos.at(0).x(),0,PatrolPos.at(0).y()));
    mScale = 1;

    d = GetDimensions();
}

void NPCwithBEZIER::Tick(float Deltatime)
{

    //Avoid using first value may be to big
    //mSpeed = 2* Deltatime; -> might break

    //clamps the values so it doesn't became to small or big value
    float Time = qBound(0.01f, Deltatime, 0.1f);//prevents Deltatime from being to big

    mSpeed = 2* Time;

    // qDebug() << "Tick called, delta: " << Deltatime;
    //qDebug() << "Speed : " << mSpeed;


    if(BezierT >= 1.0)
    {
        BezierT = 1.0f;
        BezierDirection = -1.0f;

    }
    if(BezierT <= 0.0)
    {
        BezierT = 0.0f;
        BezierDirection = 1.0f;

    }

    BezierT +=  BezierDirection*(0.2  * Time);

qDebug()<<d;

   // qDebug()<<bDetected;

    if(bDetected)
    {
        drawType = 2;
        move(Playerpos.x(),0, Playerpos.z());
        bHasReseted = false;
    }
    else
    {
        drawType = 0;
        if(!bHasReseted)
        {
            ResetNPCPos();

            if(QVector2D(GetPosition().x() - PatrolStartpos.x(), GetPosition().z() - PatrolStartpos.y()).length() < 0.01 )
            {
                bHasReseted = true;
                BezierT = 0.0f;
                qDebug() << "Back at the start";

            }

        }
    }




   // qDebug()<<BezierT;

    if(bHasReseted)
    {
        if(!PatrolPos.empty())
        {

            if(bFinishedpath && QVector2D(GetPosition().x(),GetPosition().z()).distanceToPoint(PatrolPos[3]) < 0.1f )
            {
                bFinishedpath = true;

            }
            if(!bFinishedpath && QVector2D(GetPosition().x(),GetPosition().z()).distanceToPoint(PatrolPos[0]) < 0.1f)
            {
                bFinishedpath = false;
            }



            if(!bFinishedpath)
            {
                Pos = BezierCurve(BezierT,PatrolPos[0],PatrolPos[1],PatrolPos[2],PatrolPos[3]);

            }
            else
            {
                Pos = BezierCurve(BezierT,PatrolPos[3],PatrolPos[2],PatrolPos[1],PatrolPos[0]);

            }

            //SetPosition(QVector3D(Pos.x(),0,Pos.y()));

            move(Pos.x(),0,Pos.y());



        }
        else
        {
            qDebug() << "Im Empty";
        }

    }








   // qDebug()<<GetPosition();

}

void NPCwithBEZIER::UpdateMatrix()
{
    //Provents scaling issues
    CurrentPos.setY(yPosition);
    mMatrix.setToIdentity();
    mMatrix.translate(CurrentPos);
    mMatrix.scale(GetScale());
}

void NPCwithBEZIER::SetPosition(const QVector3D &Position)
{
    CurrentPos = Position;
    UpdateMatrix();

}

QVector3D NPCwithBEZIER::GetPosition()
{
    return CurrentPos;
}

void NPCwithBEZIER::scale(float s)
{
     mScale = s;
}

float NPCwithBEZIER::GetScale()
{
    return mScale;
}

void NPCwithBEZIER::move(float x, float y, float z)
{

    QVector2D Direction = QVector2D(x,z) - QVector2D(GetPosition().x(),GetPosition().z());
    // qDebug()<<GetPosition();

    float distance = Direction.length();

    // qDebug() << distance


    if(distance > 0.1)
    {
        Direction.normalize();
        Direction *= mSpeed;
        //qDebug() << "Enemy moved to position:" << Direction.x() <<  " " << Direction.z();

        SetPosition(QVector3D(GetPosition().x() + Direction.x(), 0, GetPosition().z() + Direction.y()));
    }
    else
    {
        SetPosition(QVector3D(x,0, z));
    }



}

void NPCwithBEZIER::SetYPosition(float Y)
{
    yPosition = Y;
    UpdateMatrix();
}

QVector2D NPCwithBEZIER::BezierCurve(float t, const QVector2D p0, const QVector2D p1, const QVector2D p2, const QVector2D p3)
{
    float u = 1 - t;
    float tt =pow(t,2);
    float uu = pow(u,2);
    float uuu = pow(u,3);
    float ttt = pow(t,3);


    QVector2D point = uuu * p0; // (1-t)^3 * P0
    point += 3 * uu * t * p1;   // 3(1-t)^2 * t * P1
    point += 3 * u * tt * p2;   // 3(1-t) * t^2 * P2
    point += ttt * p3;          // t^3 * P3




    return point;

}

void NPCwithBEZIER::IsDetected(bool bIsDetected, const QVector3D &PlayerPos)
{
    bDetected = bIsDetected;
    Playerpos = PlayerPos;

}

void NPCwithBEZIER::ResetNPCPos()
{
    move(PatrolStartpos.x(),0,PatrolStartpos.y());

}
