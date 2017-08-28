#include "capppong.h"

CAppPong::CAppPong(TableInterface *ip_tbl, QObject *parent) : QObject(parent)
{
  p_table = ip_tbl;
  app_state = E_APP_STOP;

  // ball
  p_ball = new CPongBall( (float)(p_table->GetNbColumn()/2.0f), (float)(p_table->GetNbRow()/2.0f), 2000 );
  p_ball->setRgbColor(127,127,127);
  drawBall();

  // timer
  p_ctrl_timer = new QTimer(this);
  connect(p_ctrl_timer, SIGNAL(timeout()), this, SLOT(timer_ctrl_timeout()));

  p_ball_timer = new QTimer(this);
  connect(p_ball_timer, SIGNAL(timeout()), this, SLOT(timer_ball_timeout()));


  // connect button
  connect( dynamic_cast< QObject * >(p_table), SIGNAL(SignalControler1(eCtrlButton, bool)),
           this, SLOT(SlotControler1(eCtrlButton, bool)) );
}


void CAppPong::SetRunState(EAppRunningState i_run_state )
{
  app_state = i_run_state;

  if( E_APP_RUN == app_state )
  {
    p_ctrl_timer->start(250);
    p_ball_timer->start(p_ball->getSpeed());
  }
  else if( E_APP_STOP == app_state )
  {
    p_ctrl_timer->stop();
    p_ball_timer->stop();
  }
}

void CAppPong::SlotControler1( eCtrlButton i_btn, bool i_pressed )
{

}

void CAppPong::timer_ctrl_timeout(void)
{

}

void CAppPong::timer_ball_timeout(void)
{
  float l_pos_x = p_ball->getPos_x();
  float l_pos_y = p_ball->getPos_y();
  float l_dir_x = p_ball->getDir_x();
  float l_dir_y = p_ball->getDir_y();

  // clear ball
  clearBall();


  // check x colision
  if( ((l_pos_x+l_dir_x) >= p_table->GetNbColumn()) || ((l_pos_x+l_dir_x) < 0) )
  {
    // invert x direction
    l_dir_x = l_dir_x*-1.0f;
  }

  // check y colision
  if( ((l_pos_y+l_dir_y) >= p_table->GetNbRow()) || ((l_pos_y+l_dir_y) < 0) )
  {
    // invert x direction
    l_dir_y = l_dir_y*-1.0f;
  }

  // compute new position
  l_pos_x += l_dir_x;
  l_pos_y += l_dir_y;

  // save value
  p_ball->setDirection( l_dir_x, l_dir_y );
  p_ball->setPosition( l_pos_x, l_pos_y );

  // draw ball
  drawBall();
}


void CAppPong::clearBall( void )
{
  QColor l_color;
  l_color.setRgb(0,0,0);
  p_table->SetPixel(p_ball->getPos_y(),p_ball->getPos_x(),l_color);

}

void CAppPong::drawBall( void )
{
  p_table->SetPixel(p_ball->getPos_y(),p_ball->getPos_x(),p_ball->getColor());
}
