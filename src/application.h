/*
 * @Author: lmintlcx 
 * @Date: 2018-07-14 23:00:40 
 * @Description: Application.
 */

#pragma once

#include <QApplication>

class QLocalServer;

namespace Pt
{

class Application : public QApplication
{
  Q_OBJECT

public:
  Application(int, char **);
  ~Application();
  bool isRunning();

signals:
  void ActivateWindow();

private slots:
  void NewLocalConnection();

private:
  QLocalServer *server;
  bool _isRunning;
};

} // namespace Pt
