#include "FileInfoTaskbarConfig.h"
#include "ui_FileInfoTaskbarConfig.h"

FileInfoTaskbarConfig::FileInfoTaskbarConfig(QWidget *parent) :
	ConfigPage(parent),
	ui(new Ui::FileInfoTaskbarConfig)
{
	std::cout << "error FileStatusbarConfig ctor" << std::endl;
	ui->setupUi(this);
}

FileInfoTaskbarConfig::~FileInfoTaskbarConfig()
{
	std::cout << "error FileStatusbarConfig dtor" << std::endl;
	delete ui;
}


void FileInfoTaskbarConfig::load()
{
	std::cout << "error FileStatusbarConfig load" << std::endl;
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
