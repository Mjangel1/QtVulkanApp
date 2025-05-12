#include "Player.h"

Player::Player() : ObjMesh(assetPath + "cylinder.obj")
{


}

void Player::Tick(float Deltatime)
{
  mSpeed = 3* Deltatime;


}

void Player::UpdateMatrix()
{
    CurrentPos.setY(y);
    //Provents scaling issues
    mMatrix.setToIdentity();
    mMatrix.translate(CurrentPos);
    mMatrix.scale(GetScale());
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

void Player::move(float x, float y, float z)
{
    //prevents diagonal movement from being faster then 1 direction movement
    //make vector always be 1 when moving
    Direction = QVector3D(x,y,z);

    if(Direction.length() >0)
    {
         Direction.normalize();
    }

    QVector3D LastPosition = getPosition();
    QVector3D MoveDirection = (Direction*mSpeed);


    SetPostion(LastPosition +MoveDirection);

}

void Player::SetYPosition(float Y)
{
    y = Y;
    UpdateMatrix();
}
