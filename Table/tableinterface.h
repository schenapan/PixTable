#ifndef TABLEINTERFACE_H
#define TABLEINTERFACE_H

#include <QObject>

typedef enum
{
  E_BTN_A,
  E_BTN_B,
  E_BTN_UP,
  E_BTN_DOWN,
  E_BTN_LEFT,
  E_BTN_RIGHT,
  E_BTN_START,
  E_BTN_PAUSE
}eCtrlButton;

class TableInterface
{
public:
  virtual quint8 GetNbColumn( void ) = 0;
  virtual quint8 GetNbRow( void ) = 0;

  virtual void SetPixel(quint8 i_colum, quint8 i_line, QColor i_color ) = 0;
  virtual void SetPixels( QList<QPoint> i_pixels, QColor i_color ) = 0;

  virtual void DrawCircle(quint8 i_column, quint8 i_row, quint8 i_radius, QColor i_color) = 0;

  /**
   * @brief DrwHLine : draw an horizontal line from left to right
   * @param i_column : starting column
   * @param i_row : starting row
   * @param i_length : length of the line if possible, if not stop at the border of table
   * @param i_color : color of the line
   */
  virtual void DrwHLine(quint8 i_column, quint8 i_row, quint8 i_length, QColor i_color) = 0;

  /**
   * @brief DrwVLine : draw vertical line from up to down
   * @param i_column : starting column
   * @param i_row : starting line
   * @param i_length : lenght of the line if possible, if not stop at the border of table
   * @param i_color : color of the line
   */
  virtual void DrwVLine(quint8 i_column, quint8 i_row, quint8 i_length, QColor i_color) = 0;

signals:
  virtual void SignalControler1( eCtrlButton i_btn, bool i_pressed ) = 0;
};


#endif // TABLEINTERFACE_H
