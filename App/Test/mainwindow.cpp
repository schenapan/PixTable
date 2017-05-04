#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

QList<QPoint> g_f0({QPoint(0,0),QPoint(1,0),QPoint(2,0),QPoint(3,0),QPoint(0,1),QPoint(3,1),QPoint(0,2),QPoint(3,2)});


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  ui->tblLayout->addWidget(&table);

  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(timer_timeout()));
  timer->start(1000);

  QColor l_color;
  l_color.setRgb(0,0,128);
  table.DrawCircle(10, 10, 9, l_color);

  table.SetPixels(g_f0,l_color);

}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::timer_timeout(void)
{
  static bool l_toggle = true;

  if( l_toggle )
    {
      QColor l_color;
      l_color.setRgb(10,10,10);
      table.SetPixel(0,0,l_color);
      l_toggle = false;
    }
  else
    {
      QColor l_color;
      l_color.setRgb(192,192,192);
      table.SetPixel(0,0,l_color);
      l_toggle = true;
    }

}
