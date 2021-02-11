#include "FileInfoTaskbarSettings.h"
#include "gui/settings/rsharesettings.h"

FileInfoTaskbarSettings::FileInfoTaskbarSettings(QObject *parent) : QObject(parent)
{
	load();
}

void FileInfoTaskbarSettings::save()
{
	Settings->beginGroup(settingsgroup);

	Settings->setValue("bytes", bytes);
	Settings->setValue("allfinishedcolor", allfinishedcolor);
	Settings->setValue("stuckcolor", stuckcolor);
	Settings->setValue("activecolor", activecolor);

	Settings->endGroup();
}

void FileInfoTaskbarSettings::load()
{
	Settings->beginGroup(settingsgroup);

	bytes = Settings->value("bytes", true).toBool();
	allfinishedcolor = Settings->value("allfinishedcolor", TaskbarColors::Green).toInt();
	stuckcolor = Settings->value("stuckcolor", TaskbarColors::Yellow).toInt();
	activecolor = Settings->value("activecolor", TaskbarColors::Green).toInt();

	Settings->endGroup();
}
