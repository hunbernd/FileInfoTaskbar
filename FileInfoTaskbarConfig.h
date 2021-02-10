#ifndef FILESTATUSBARCONFIG_H
#define FILESTATUSBARCONFIG_H

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

private:
	Ui::FileInfoTaskbarConfig *ui;

	// ConfigPage interface
public:
	void load();
	QPixmap iconPixmap() const;
	QString pageName() const;
	QString helpText() const;
};

#endif // FILESTATUSBARCONFIG_H
