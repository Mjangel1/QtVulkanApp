#include "Player.h"

Player::Player() : ObjMesh(assetPath + "cylinder.obj")
{
    drawType = 0;


    setName("Player");
    ScaleXY(0.5f,2);

    ColliderAB = new ColliderAABB();
    SetColliderAABB(ColliderAB);

    ColliderAB->SetColliderPosition(GetPosition());
    ColliderAB->SetSize((GetDimensions()*GetScaleXY())/ 2);

}

void Player::Tick(float Deltatime)
{

    UpdateCollider();

   // qDebug()<<GetColliderAABB().GetSize();

    //qDebug()<<GetScaleXY();
    mSpeed = 3* Deltatime;


    //qDebug()<< GetPosition().y();

    if(!bInsideMap)
    {
        //qDebug() << "outside";
        OutsideBoundry();
    }

    //qDebug()<<bInsideMap;

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

QVector3D Player::GetScaleXY()
{
    return QVector3D(mScaleX,mScaleY,1);
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


   // qDebug()<< GetPosition() + MoveDirection;

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

void Player::UpdateCollider()
{
    GetColliderAABB().SetColliderPosition(GetPosition());
   // ColliderAB->SetSize((GetDimensions() * GetScale())/2);

}
