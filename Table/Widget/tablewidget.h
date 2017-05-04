#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QWidget>
#include <QList>
#include <QPoint>

namespace Ui {
  class TableWidget;
}

#define NB_COLUMN 20
#define NB_ROW 20

class TableWidget : public QWidget
{
  Q_OBJECT

public:
  explicit TableWidget(QWidget *parent = 0);
  ~TableWidget();

  quint8 GetNbColumn( void ){return NB_COLUMN;}
  quint8 GetYNbRow( void ){return NB_ROW;}


  void SetPixel(quint8 i_colum, quint8 i_line, QColor i_color );
  void SetPixels( QList<QPoint> i_pixels, QColor i_color );

  void DrawCircle(quint8 i_column, quint8 i_row, quint8 i_radius, QColor i_color);



private:
  Ui::TableWidget *ui;
};

#endif // TABLEWIDGET_H
