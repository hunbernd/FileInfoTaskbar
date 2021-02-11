#ifndef FILEINFOTASKBARSETTINGS_H
#define FILEINFOTASKBARSETTINGS_H

#include <QObject>

enum TaskbarColors
{
	None = 0,
	Green = 1,
	Yellow = 2,
	Red = 3
};

class FileInfoTaskbarSettings : public QObject
{
	Q_OBJECT
public:
	explicit FileInfoTaskbarSettings(QObject *parent = nullptr);
	void save();
	void load();
	bool bytes;
	int activecolor;
	int stuckcolor;
	int allfinishedcolor;

private:
	const QString settingsgroup = QString("FileInfoTaskbarSettings");

signals:

};

#endif // FILEINFOTASKBARSETTINGS_H
