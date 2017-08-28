#ifndef CPONGBALL_H
#define CPONGBALL_H

#include <QObject>
#include <QPoint>
#include <QColor>

class CPongBall : public QObject
{
  Q_OBJECT
public:
  explicit CPongBall(float i_pos_x, float i_pos_y, quint8 i_speed, QObject *parent = 0);

  quint8 getSpeed() const;
  void setSpeed(const quint8 &value);

  void setPosition( float i_pos_x, float i_pos_y ){ pos_x = i_pos_x; pos_y = i_pos_y; }

  void setDirection( float i_dir_x, float i_dir_y ){ dir_x = i_dir_x; dir_y = i_dir_y; }

  float getPos_x() const;
  void setPos_x(float value);

  float getPos_y() const;
  void setPos_y(float value);

  float getDir_x() const;
  void setDir_x(float value);

  float getDir_y() const;
  void setDir_y(float value);

  QColor getColor() const;
  void setColor(const QColor &value);
  void setRgbColor(quint8 i_r, quint8 i_g, quint8 i_b);

private:
  quint8 speed;
  float pos_x;
  float pos_y;
  float dir_x;
  float dir_y;
  QColor color;

};

#endif // CPONGBALL_H
