#ifndef FULLTABLE_H
#define FULLTABLE_H

#include <QMainWindow>

#include "../tableinterface.h"

namespace Ui {
  class FullTable;
}

#define NB_COLUMN 20
#define NB_ROW 20

class FullTable : public QMainWindow, public TableInterface
{
  Q_OBJECT

public:
  explicit FullTable(QWidget *parent = 0);
  ~FullTable();

  quint8 GetNbColumn( void ){return NB_COLUMN;}
  quint8 GetNbRow( void ){return NB_ROW;}


  void SetPixel(quint8 i_colum, quint8 i_line, QColor i_color );
  void SetPixels( QList<QPoint> i_pixels, QColor i_color );

  void DrawCircle(quint8 i_column, quint8 i_row, quint8 i_radius, QColor i_color);

private:
  Ui::FullTable *ui;
};

#endif // FULLTABLE_H
