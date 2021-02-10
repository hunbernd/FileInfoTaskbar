#ifndef STATUSBARHANDLER_H
#define STATUSBARHANDLER_H

#include <QObject>
#include <QTimer>
#include <QWinTaskbarButton>
#include <QWinTaskbarProgress>

#include <retroshare/rsfiles.h>

class TaskbarHandler : public QObject
{
	Q_OBJECT
public:
	explicit TaskbarHandler(QWidget *parent = nullptr);
	void start(RsFiles *files);
	void stop();

private:
	RsFiles *mFiles;
	QTimer *timer;
	QWinTaskbarProgress *progressbar = nullptr;
	QWinTaskbarButton *button = nullptr;
	QWidget *configPage;
	bool checkWindow();
	bool haswWindow = false;

private slots:
	void tick();

signals:

};

#endif // STATUSBARHANDLER_H
