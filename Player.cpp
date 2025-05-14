#include "Player.h"

Player::Player() : ObjMesh(assetPath + "cylinder.obj")
{
    drawType = 0;


    setName("Player");
}

void Player::Tick(float Deltatime)
{
    //may cause a small value to appear when the first deltatime starts
 // mSpeed = 3* Deltatime; -> dont use

    //prevents the value from being to big
    mSpeed = 3 * qBound(0.01f, Deltatime, 0.1f);



    //qDebug()<< GetPosition().y();

    if(!bInsideMap)
    {
        //qDebug() << "outside";
        OutsideBoundry();
    }

    qDebug()<<bInsideMap;

}

void Player::UpdateMatrix()
{

    //Provents scaling issues
    mMatrix.setToIdentity();
    CurrentPos.setY(y);
    mMatrix.translate(CurrentPos);

    //mMatrix.scale(GetScale());
    mMatrix.scale(mScaleX,mScaleY);
}

void Player::SetPostion(const QVector3D &Position)
{
    CurrentPos = Position;
    UpdateMatrix();


}

QVector3D Player::GetPosition()
{
    return CurrentPos;
}

void Player::scale(float s)
{
    mScale= s;
    UpdateMatrix();
}

float Player::GetScale()
{
    return mScale;
}

void Player::ScaleXY(float x, float y)
{
    mScaleX = x;
    mScaleY = y;
}

void Player::move(float x, float y, float z)
{
    //prevents diagonal movement from being faster then 1 direction movement
    //make vector always be 1 when moving
    Direction = QVector3D(x,y,z);

    if(Direction.length() >0)
    {
         Direction.normalize();
    }

    if(bInsideMap)
    {
        LastPosition = getPosition();
    }

    QVector3D MoveDirection = (Direction*mSpeed);




    SetPostion(GetPosition() + MoveDirection);

}

void Player::SetYPosition(float Y)
{
    if(bInsideMap)
    {
        y = Y;

    }
    else
    {
        y = LastPosition.y();
    }

    UpdateMatrix();
}

void Player::OutsideBoundry()
{

    SetPostion(LastPosition);

}

bool Player::getIsInsideMap(bool IsInside)
{
    bInsideMap = IsInside;
    return bInsideMap;

}
