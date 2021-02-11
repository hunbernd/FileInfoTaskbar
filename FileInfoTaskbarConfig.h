#ifndef FILESTATUSBARCONFIG_H
#define FILESTATUSBARCONFIG_H

#include "FileInfoTaskbarSettings.h"

#include <QComboBox>
#include <QWidget>

#include <retroshare-gui/configpage.h>

namespace Ui {
class FileInfoTaskbarConfig;
}

class FileInfoTaskbarConfig : public ConfigPage
{
	Q_OBJECT

public:
	explicit FileInfoTaskbarConfig(QWidget *parent = nullptr);
	~FileInfoTaskbarConfig();
	FileInfoTaskbarSettings* getSettings();

private:
	Ui::FileInfoTaskbarConfig *ui;
	FileInfoTaskbarSettings *settings;
	void fillColorCombobox(QComboBox *cb);

private slots:
	void configChanged();

	// ConfigPage interface
public:
	void load();
	virtual bool save(QString &errmsg);
	QPixmap iconPixmap() const;
	QString pageName() const;
	QString helpText() const;
};

#endif // FILESTATUSBARCONFIG_H
