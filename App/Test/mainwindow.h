#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../../Table/Widget/tablewidget.h"

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();


private slots:
  void timer_timeout(void);

private:
  Ui::MainWindow *ui;
  TableWidget table;
};

#endif // MAINWINDOW_H
