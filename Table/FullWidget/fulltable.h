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

  /**
   * @brief DrwHLine : draw an horizontal line from left to right
   * @param i_column : starting column
   * @param i_row : starting row
   * @param i_color : color of the line
   */
  void DrwHLine(quint8 i_column, quint8 i_row, quint8 i_length, QColor i_color);

  /**
   * @brief DrwVLine : draw vertical line from up to down
   * @param i_column : starting column
   * @param i_row : starting line
   * @param i_length : lenght of the line if possible, if not stop at the border of table
   * @param i_color : color of the line
   */
  void DrwVLine(quint8 i_column, quint8 i_row, quint8 i_length, QColor i_color);

private slots:
  void on_btnA_pressed();

  void on_btnA_released();

  void on_btnB_pressed();

  void on_btnB_released();

  void on_btnLeft_pressed();

  void on_btnLeft_released();

  void on_btnRight_pressed();

  void on_btnRight_released();

  void on_btnUp_pressed();

  void on_btnUp_released();

  void on_btnDown_pressed();

  void on_btnDown_released();

signals:
  void SignalControler1( eCtrlButton i_btn, bool i_pressed );

private:
  Ui::FullTable *ui;
};

#endif // FULLTABLE_H
