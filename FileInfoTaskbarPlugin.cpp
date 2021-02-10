#include <retroshare/rsplugin.h>

#include <QApplication>

#include "FileInfoTaskbarPlugin.h"
#include "FileInfoTaskbarConfig.h"

extern "C" {
#ifdef WIN32
	__declspec(dllexport)
#endif
	RsPlugin *RETROSHARE_PLUGIN_provide()
	{
		return new FileInfoTaskbarPlugin();
	}

	// This symbol contains the svn revision number grabbed from the executable.
	// It will be tested by RS to load the plugin automatically, since it is safe to load plugins
	// with same revision numbers, assuming that the revision numbers are up-to-date.
	//
#ifdef WIN32
	__declspec(dllexport)
#endif
	uint32_t RETROSHARE_PLUGIN_revision = (uint32_t)atoi(RS_EXTRA_VERSION);

	// This symbol contains the svn revision number grabbed from the executable.
	// It will be tested by RS to load the plugin automatically, since it is safe to load plugins
	// with same revision numbers, assuming that the revision numbers are up-to-date.
	//
#ifdef WIN32
	__declspec(dllexport)
#endif
	uint32_t RETROSHARE_PLUGIN_api = RS_PLUGIN_API_VERSION ;
}

void FileInfoTaskbarPlugin::getPluginVersion(int& major, int& minor, int &build, int& svn_rev) const
{
	major = RS_MAJOR_VERSION;
	minor = RS_MINOR_VERSION;
	build = RS_MINI_VERSION;
	svn_rev = abs(atoi(RS_EXTRA_VERSION)) ;
}

FileInfoTaskbarPlugin::FileInfoTaskbarPlugin()
{
	std::cout << "error FileStatusbarPlugin ctor" << std::endl;
	mPlugInHandler = NULL;
}

void FileInfoTaskbarPlugin::setInterfaces(RsPlugInInterfaces &interfaces)
{
	std::cout << "error FileStatusbarPlugin setInterfaces" << std::endl;
	mInterfaces = interfaces;
}

ConfigPage *FileInfoTaskbarPlugin::qt_config_page() const
{
	std::cout << "error FileStatusbarPlugin qt_config_page begin" << std::endl;
	FileInfoTaskbarConfig *fstbc = new FileInfoTaskbarConfig();
	stbh = new TaskbarHandler(fstbc);
	stbh->start(mInterfaces.mFiles);
	std::cout << "error FileStatusbarPlugin qt_config_page end" << std::endl;
	return fstbc;
}

void FileInfoTaskbarPlugin::stop()
{
	std::cout << "error FileStatusbarPlugin stop begin" << std::endl;
//	if(stbh) {
//		stbh->stop();
//		delete stbh;
//		stbh = nullptr;
//	}
	std::cout << "error FileStatusbarPlugin stop end" << std::endl;
}

void FileInfoTaskbarPlugin::setPlugInHandler(RsPluginHandler *pgHandler)
{
	std::cout << "error FileStatusbarPlugin setPlugInHandler" << std::endl;
	mPlugInHandler = pgHandler;
}

std::string FileInfoTaskbarPlugin::getShortPluginDescription() const
{
	std::cout << "error FileStatusbarPlugin getShortPluginDescription" << std::endl;
	return QApplication::translate("FileInfoTaskbarPlugin", "Displays file download status on Windows taskbar.").toUtf8().constData();
}

std::string FileInfoTaskbarPlugin::getPluginName() const
{
	std::cout << "error FileStatusbarPlugin getPluginName" << std::endl;
	return QApplication::translate("FileInfoTaskbarPlugin", "FileInfoTaskbar").toUtf8().constData();
}
