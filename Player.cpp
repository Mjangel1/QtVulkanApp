#include "Player.h"

Player::Player() : ObjMesh(assetPath + "cube.obj")
{


}

void Player::Tick(float Deltatime)
{
  mSpeed = 3* Deltatime;

}

void Player::UpdateMatrix()
{
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


    float XDirection = x * mSpeed;
    float ZDirection = z * mSpeed;

    QVector3D LastPosition = getPosition();


    SetPostion(LastPosition+QVector3D(XDirection,0,ZDirection));

}
