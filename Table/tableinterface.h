#ifndef TABLEINTERFACE_H
#define TABLEINTERFACE_H

#include <QObject>

class TableInterface
{
public:
  virtual quint8 GetNbColumn( void ) = 0;
  virtual quint8 GetNbRow( void ) = 0;

  virtual void SetPixel(quint8 i_colum, quint8 i_line, QColor i_color ) = 0;
  virtual void SetPixels( QList<QPoint> i_pixels, QColor i_color ) = 0;

  virtual void DrawCircle(quint8 i_column, quint8 i_row, quint8 i_radius, QColor i_color) = 0;
};


#endif // TABLEINTERFACE_H
