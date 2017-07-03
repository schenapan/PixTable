#include "fulltable.h"
#include "ui_fulltable.h"

FullTable::FullTable(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::FullTable)
{
  ui->setupUi(this);

  // create row and colum
  ui->tableWidget->setRowCount(NB_ROW);
  ui->tableWidget->setColumnCount(NB_COLUMN);

  // add item in each cell
  QColor l_color;
  l_color.setRgb(0,0,0);
  for( quint8 colum_loop=0; colum_loop<NB_COLUMN; colum_loop++)
    {
      for( quint8 row_loop=0; row_loop<NB_ROW; row_loop++)
        {
          ui->tableWidget->setItem(row_loop,colum_loop,new QTableWidgetItem);
          SetPixel(row_loop,colum_loop,l_color);
        }
    }

}

FullTable::~FullTable()
{
  delete ui;
}

void FullTable::SetPixel( quint8 i_colum, quint8 i_line, QColor i_color )
{
  ui->tableWidget->item(i_colum, i_line)->setBackgroundColor(i_color);
}

void FullTable::SetPixels( QList<QPoint> i_pixels, QColor i_color )
{
  foreach (QPoint l_point, i_pixels)
  {
    SetPixel(l_point.x(),l_point.y(),i_color);
  }

}


void FullTable::DrawCircle(quint8 i_column, quint8 i_row, quint8 i_radius, QColor i_color)
{
    qint16 x = 0;
    qint16 y = i_radius;
    qint16 d = i_radius - 1;

    while (y >= x)
    {
        SetPixel(i_column + x, i_row + y, i_color);
        SetPixel(i_column + y, i_row + x, i_color);
        SetPixel(i_column - x, i_row + y, i_color);
        SetPixel(i_column - y, i_row + x, i_color);
        SetPixel(i_column + x, i_row - y, i_color);
        SetPixel(i_column + y, i_row - x, i_color);
        SetPixel(i_column - x, i_row - y, i_color);
        SetPixel(i_column - y, i_row - x, i_color);

        if (d >= 2 * x)
        {
            d -= 2 * x + 1;
            x++;
        }
        else if (d < 2 * (i_radius - y))
        {
            d += 2 * y - 1;
            y--;
        }
        else
        {
            d += 2 * (y - x - 1);
            y--;
            x++;
        }
    }
}

/**
 * @brief DrwHLine : draw an horizontal line from left to right
 * @param i_column : starting column
 * @param i_row : starting row
 * @param i_length : length of the line if possible, if not stop at the border of table
 * @param i_color : color of the line
 */
void FullTable::DrwHLine(quint8 i_column, quint8 i_row, quint8 i_length, QColor i_color)
{
  // compute real length
  quint8 l_length = i_length;

  if( (i_column+l_length) > NB_COLUMN )
    {
      l_length = NB_COLUMN - i_column;
    }

  for( int loop=0; loop<l_length; loop++ )
    {
      SetPixel(i_column +loop, i_row, i_color);
    }
}
