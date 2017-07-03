#ifndef CAPPCLOCK_H
#define CAPPCLOCK_H

#include <QObject>

#include "../appinterface.h"
#include "../../Table/tableinterface.h"

class CAppClock : public QObject, public AppInterface
{
  Q_OBJECT
public:
  explicit CAppClock(TableInterface *ip_tbl, QObject *parent = 0);

  void SetRunState(EAppRunningState i_run_state );

signals:

public slots:

private slots:
  void timer_timeout(void);

private:
  TableInterface *p_table;
  EAppRunningState app_state;
};

#endif // CAPPCLOCK_H
