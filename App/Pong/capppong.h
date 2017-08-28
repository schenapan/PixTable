#ifndef CAPPPONG_H
#define CAPPPONG_H

#include <QObject>
#include <QTimer>

#include "cpongball.h"

#include "../appinterface.h"
#include "../../Table/tableinterface.h"

class CAppPong : public QObject, public AppInterface
{
  Q_OBJECT
public:
  explicit CAppPong(TableInterface *ip_tbl, QObject *parent = 0);
  void SetRunState(EAppRunningState i_run_state );

private:
  void clearBall( void );
  void drawBall( void );


signals:

public slots:

private slots:
  void timer_ctrl_timeout(void);
  void timer_ball_timeout(void);
  void SlotControler1( eCtrlButton i_btn, bool i_pressed );

private:
  TableInterface *p_table;
  EAppRunningState app_state;

  CPongBall *p_ball;

  QTimer *p_ctrl_timer;
  QTimer *p_ball_timer;

  quint16 ball_speed; // vitesse de rafraichissement de la balle



};

#endif // CAPPPONG_H
