#include "cpongball.h"

CPongBall::CPongBall(float i_pos_x, float i_pos_y, quint8 i_speed, QObject *parent ) : QObject(parent)
{
  pos_x = i_pos_x;
  pos_y = i_pos_y;
  speed = i_speed;

  // random direction
  dir_x = 0.5;
  dir_y = -1;
}

quint8 CPongBall::getSpeed() const
{
  return speed;
}

void CPongBall::setSpeed(const quint8 &value)
{
  speed = value;
}

float CPongBall::getPos_x() const
{
  return pos_x;
}

void CPongBall::setPos_x(float value)
{
  pos_x = value;
}

float CPongBall::getPos_y() const
{
  return pos_y;
}

void CPongBall::setPos_y(float value)
{
  pos_y = value;
}

float CPongBall::getDir_x() const
{
  return dir_x;
}

void CPongBall::setDir_x(float value)
{
  dir_x = value;
}

float CPongBall::getDir_y() const
{
  return dir_y;
}

void CPongBall::setDir_y(float value)
{
  dir_y = value;
}

QColor CPongBall::getColor() const
{
  return color;
}

void CPongBall::setColor(const QColor &value)
{
  color = value;
}

void CPongBall::setRgbColor(quint8 i_r, quint8 i_g, quint8 i_b)
{
  color.setRgb(i_r,i_g,i_b);
}
