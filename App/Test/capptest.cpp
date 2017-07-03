#include "capptest.h"

#include <QList>
#include <QPoint>
#include <QColor>

QList<QPoint> g_f0({QPoint(0,0),QPoint(1,0),QPoint(2,0),QPoint(3,0),QPoint(0,1),QPoint(3,1),QPoint(0,2),QPoint(3,2)});

CAppTest::CAppTest(TableInterface *ip_tbl, QObject *parent) : QObject(parent)
{
  p_table = ip_tbl;

  QColor l_color;
  l_color.setRgb(0,0,128);
  p_table->DrawCircle(10, 10, 9, l_color);

  p_table->SetPixels(g_f0,l_color);
}

void CAppTest::SetRunState(EAppRunningState i_run_state )
{
  app_state = i_run_state;
}
