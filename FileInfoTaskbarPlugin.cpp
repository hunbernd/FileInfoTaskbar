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
	mPlugInHandler = NULL;
}

void FileInfoTaskbarPlugin::setInterfaces(RsPlugInInterfaces &interfaces)
{
	mInterfaces = interfaces;
}

ConfigPage *FileInfoTaskbarPlugin::qt_config_page() const
{
	FileInfoTaskbarConfig *fstbc = new FileInfoTaskbarConfig();
	stbh = new TaskbarHandler(fstbc);
	stbh->start(mInterfaces.mFiles);
	return fstbc;
}

void FileInfoTaskbarPlugin::stop()
{
//	if(stbh) {
//		stbh->stop();
//		delete stbh;
//		stbh = nullptr;
//	}
}

void FileInfoTaskbarPlugin::setPlugInHandler(RsPluginHandler *pgHandler)
{
	mPlugInHandler = pgHandler;
}

std::string FileInfoTaskbarPlugin::getShortPluginDescription() const
{
	return QApplication::translate("FileInfoTaskbarPlugin", "Displays file download status on Windows taskbar.").toUtf8().constData();
}

std::string FileInfoTaskbarPlugin::getPluginName() const
{
	return QApplication::translate("FileInfoTaskbarPlugin", "FileInfoTaskbar").toUtf8().constData();
}
