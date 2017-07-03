#ifndef CAPPTEST_H
#define CAPPTEST_H

#include <QObject>

#include "../appinterface.h"
#include "../../Table/tableinterface.h"

class CAppTest : public QObject, public AppInterface
{
  Q_OBJECT
public:
  explicit CAppTest(TableInterface *ip_tbl,QObject *parent = 0);

  void SetRunState(EAppRunningState i_run_state );

signals:

public slots:

private:
  TableInterface *p_table;
  EAppRunningState app_state;
};

#endif // CAPPTEST_H
