#include "tablewidget.h"
#include "ui_tablewidget.h"

TableWidget::TableWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::TableWidget)
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

TableWidget::~TableWidget()
{
  delete ui;
}

void TableWidget::SetPixel( quint8 i_colum, quint8 i_line, QColor i_color )
{
  ui->tableWidget->item(i_colum, i_line)->setBackgroundColor(i_color);
}

void TableWidget::SetPixels( QList<QPoint> i_pixels, QColor i_color )
{
  foreach (QPoint l_point, i_pixels)
  {
    SetPixel(l_point.x(),l_point.y(),i_color);
  }

}


void TableWidget::DrawCircle(quint8 i_column, quint8 i_row, quint8 i_radius, QColor i_color)
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
