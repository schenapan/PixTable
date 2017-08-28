//#include <QCoreApplication>
#include <QApplication>

#include "../Table/FullWidget/fulltable.h"

#include "../App/Clock/cappclock.h"
#include "../App/Pong/capppong.h"

int main(int argc, char *argv[])
{
  //QCoreApplication a(argc, argv);
  QApplication a(argc, argv);

  // table
  FullTable w;
  w.show();

  // app
  /*
  CAppClock *clock;
  clock = new CAppClock(&w);
*/

  CAppPong *pong;
  pong = new CAppPong(&w);
  pong->SetRunState(E_APP_RUN);

  return a.exec();
}
