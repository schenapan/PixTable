#ifndef APPINTERFACE_H
#define APPINTERFACE_H

#include <QObject>

typedef enum {
	E_APP_RUN,	// app is in first plane and have the hand.
	E_APP_STOP, // app is stop, another app is running
}EAppRunningState;

class AppInterface
{
public:
  virtual void SetRunState(EAppRunningState i_run_state ) = 0;
};


#endif // APPINTERFACE_H
