//#include <QCoreApplication>
#include <QApplication>

#include "../Table/FullWidget/fulltable.h"

#include "../App/Clock/cappclock.h"

int main(int argc, char *argv[])
{
  //QCoreApplication a(argc, argv);
  QApplication a(argc, argv);

  // table
  FullTable w;
  w.show();

  // app
  CAppClock *clock;
  clock = new CAppClock(&w);


  return a.exec();
}
