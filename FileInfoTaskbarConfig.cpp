#include "FileInfoTaskbarConfig.h"
#include "ui_FileInfoTaskbarConfig.h"

FileInfoTaskbarConfig::FileInfoTaskbarConfig(QWidget *parent) :
	ConfigPage(parent),
	ui(new Ui::FileInfoTaskbarConfig)
{
	std::cout << "error FileStatusbarConfig ctor" << std::endl;
	ui->setupUi(this);
	settings = new FileInfoTaskbarSettings(this);
	ui->cbBytes->addItem("Files", false);
	ui->cbBytes->addItem("Bytes", true);
	connect(ui->cbBytes, QOverload<int>::of(&QComboBox::activated), this, &FileInfoTaskbarConfig::configChanged);
	fillColorCombobox(ui->cbAll);
	fillColorCombobox(ui->cbActive);
	fillColorCombobox(ui->cbStuck);
}

FileInfoTaskbarConfig::~FileInfoTaskbarConfig()
{
	std::cout << "error FileStatusbarConfig dtor" << std::endl;
	delete ui;
}

FileInfoTaskbarSettings *FileInfoTaskbarConfig::getSettings()
{
	return settings;
}

void FileInfoTaskbarConfig::fillColorCombobox(QComboBox *cb)
{
	cb->addItem("None", TaskbarColors::None);
	cb->addItem("Green", TaskbarColors::Green);
	cb->addItem("Yellow", TaskbarColors::Yellow);
	cb->addItem("Red", TaskbarColors::Red);
	connect(cb, QOverload<int>::of(&QComboBox::activated), this, &FileInfoTaskbarConfig::configChanged);
}

void FileInfoTaskbarConfig::configChanged()
{
	QString msg;
	save(msg);
}


void FileInfoTaskbarConfig::load()
{
	std::cout << "error FileStatusbarConfig load" << std::endl;
	settings->load();
	ui->cbBytes->setCurrentIndex(settings->bytes ? 1: 0);
	ui->cbActive->setCurrentIndex(settings->activecolor);
	ui->cbStuck->setCurrentIndex(settings->stuckcolor);
	ui->cbAll->setCurrentIndex(settings->allfinishedcolor);
}

bool FileInfoTaskbarConfig::save(QString &errmsg)
{
	settings->bytes = ui->cbBytes->currentData().toBool();
	settings->activecolor = ui->cbActive->currentData().toInt();
	settings->stuckcolor = ui->cbStuck->currentData().toInt();
	settings->allfinishedcolor = ui->cbAll->currentData().toInt();
	settings->save();
	return true;
}

QPixmap FileInfoTaskbarConfig::iconPixmap() const
{
	std::cout << "error FileStatusbarConfig iconPixmap" << std::endl;
	const QPixmap pm;
	return pm;
}

QString FileInfoTaskbarConfig::pageName() const
{
	std::cout << "error FileStatusbarConfig pageName" << std::endl;
	return QString("Download statusbar");
}

QString FileInfoTaskbarConfig::helpText() const
{
	std::cout << "error FileStatusbarConfig helpText" << std::endl;
	return QString();
}
