#ifndef STATUSBARHANDLER_H
#define STATUSBARHANDLER_H

#include "FileInfoTaskbarConfig.h"

#include <QObject>
#include <QTimer>
#include <QWinTaskbarButton>
#include <QWinTaskbarProgress>

#include <retroshare/rsfiles.h>

class TaskbarHandler : public QObject
{
	Q_OBJECT
public:
	explicit TaskbarHandler(FileInfoTaskbarConfig *parent = nullptr);
	void start(RsFiles *files);
	void stop();

private:
	RsFiles *mFiles;
	QTimer *timer;
	QWinTaskbarProgress *progressbar = nullptr;
	QWinTaskbarButton *button = nullptr;
	FileInfoTaskbarConfig *configPage;
	bool checkWindow();
	bool haswWindow = false;
	void setProgress(int color, int percent);

private slots:
	void tick();

signals:

};

#endif // STATUSBARHANDLER_H
