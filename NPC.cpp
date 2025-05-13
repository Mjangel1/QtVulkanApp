#include "NPC.h"

NPC::NPC() : ObjMesh(assetPath + "cylinder.obj")
{
   // -2.5, -2.0), (1.0, -0.5), (-1.5, 1.0), and (1.5, 2.5)

    PatrolPos.push_back(QVector2D(-2.5,-2.0));
    PatrolPos.push_back(QVector2D(1.0,0.50));
    PatrolPos.push_back(QVector2D(-1.5,1.0));
    PatrolPos.push_back(QVector2D(1.5,2.5));

    SetPosition(QVector3D(PatrolPos.at(0).x(),0,PatrolPos.at(0).y()));



}

void NPC::Tick(float Deltatime)
{

    //Avoid using first value may be to big
    //mSpeed = 2* Deltatime; -> might break

    //clamps the values so it doesn't became to small or big value
    float Time = qBound(0.01f, Deltatime, 0.1f);//prevents Deltatime from being to big

    mSpeed = 2 * Time;

   // qDebug() << "Tick called, delta: " << Deltatime;
    //qDebug() << "Speed : " << mSpeed;

    if(bDetected)
    {
        drawType = 2;

    }
    else drawType = 0;


    if(!PatrolPos.empty())
    {
        Patrol(PatrolPos[T]);
    }
    else
    {
        qDebug() << "Im Empty";
    }

    //qDebug() <<GetPosition();
}

void NPC::UpdateMatrix()
{

    //Provents scaling issues
    CurrentPos.setY(yPosition);
    mMatrix.setToIdentity();
    mMatrix.translate(CurrentPos);
    mMatrix.scale(GetScale());

}

void NPC::SetPosition(const QVector3D &Position)
{
    CurrentPos = Position;
    UpdateMatrix();

}

QVector3D NPC::GetPosition()
{
    return CurrentPos;
}

void NPC::scale(float s)
{
    mScale = s;
}

float NPC::GetScale()
{
    return mScale;
}

void NPC::move(float x, float y, float z)
{

    QVector3D NewPos (x,y,z);

    QVector3D LastPosition = GetPosition();

    SetPosition(LastPosition + NewPos);


}

void NPC::SetYPosition(float Y)
{
    yPosition = Y;
    UpdateMatrix();

}

void NPC::Patrol(const QVector2D &Positions)
{

    //Change from 3d to 2d since calculating the y from barycentric causes it to break
    QVector2D Direction = QVector2D(Positions.x(),Positions.y()) - QVector2D(GetPosition().x(),GetPosition().z());
   // qDebug()<<GetPosition();

    float distance = Direction.length();

  // qDebug() << distance


    if(distance > 0.05)
    {
        Direction.normalize();
        Direction *= mSpeed;
        //qDebug() << "Enemy moved to position:" << Direction.x() <<  " " << Direction.z();

        move(Direction.x(), 0, Direction.y());
    }
    else
    {
        SetPosition(QVector3D(Positions.x(),0, Positions.y()));
        //qDebug() << "Enemy Reached Location";
        T++;

        if(T >= PatrolPos.size())
        {

            T= 0;

        }

    }
}


