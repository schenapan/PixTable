#include "cappclock.h"

#include <QTimer>
#include <QList>
#include <QPoint>
#include <QColor>

#include <QTime>

CAppClock::CAppClock(TableInterface *ip_tbl, QObject *parent) : QObject(parent)
{
  p_table = ip_tbl;

  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(timer_timeout()));
  timer->start(1000);

  // connect button
  connect( dynamic_cast< QObject * >(p_table), SIGNAL(SignalControler1(eCtrlButton, bool)),
           this, SLOT(SlotControler1(eCtrlButton, bool)) );

  color_state = false;

}

void CAppClock::SetRunState(EAppRunningState i_run_state )
{
  app_state = i_run_state;
}

void CAppClock::SlotControler1( eCtrlButton i_btn, bool i_pressed )
{
  if( E_BTN_A == i_btn )
  {
    color_state = i_pressed;
  }
}

void CAppClock::timer_timeout(void)
{
  static bool l_toggle = true;

  int l_minute = QTime::currentTime().minute();
  int l_heure = QTime::currentTime().hour();

  QColor l_color;
  int line_loop;

/*
  if ( l_minute == 0 )
    {
      QColor l_color;
      l_color.setRgb(255,150,140);
      p_table->SetPixel(9,7,l_color);
      p_table->SetPixel(10,7,l_color);
      p_table->SetPixel(11,7,l_color);
      p_table->SetPixel(9,6,l_color);
      p_table->SetPixel(11,6,l_color);
      p_table->SetPixel(11,5,l_color);
      p_table->SetPixel(9,5,l_color);
      p_table->SetPixel(10,5,l_color);
    }
*/

  // heure
  line_loop = 0;
  l_color.setRgb(140,150,255);
  while( l_heure > 0 )
    {
      int l_end_column;
      if( l_heure >= 20 )
        l_end_column = 20;
      else
        l_end_column = l_heure%20;

      for(int column_loop=0; column_loop<l_end_column; column_loop++)
        {
          p_table->SetPixel(line_loop,column_loop,l_color);

        }
      l_heure = l_heure - 20;
      line_loop = line_loop + 1;

    }

  // minute
  line_loop = 2;
  l_color.setRgb(255,150,140);
  while( l_minute > 0 )
    {
      int l_end_column;
      if( l_minute >= 20 )
        l_end_column = 20;
      else
        l_end_column = l_minute%20;

      for(int column_loop=0; column_loop<l_end_column; column_loop++)
        {
          p_table->SetPixel(line_loop,column_loop,l_color);

        }
      l_minute = l_minute - 20;
      line_loop = line_loop + 1;

    }





  if( l_toggle )
    {
      QColor l_color;
      if( color_state )
      {
        l_color.setRgb(255,150,140);
      }
      else
      {
        l_color.setRgb(140,150,255);
      }
      p_table->SetPixel(9,9,l_color);
      p_table->SetPixel(11,9,l_color);
      l_toggle = false;
    }
  else
    {
      QColor l_color;
      l_color.setRgb(10,10,10);
      p_table->SetPixel(9,9,l_color);
      p_table->SetPixel(11,9,l_color);
      l_toggle = true;
    }
}


