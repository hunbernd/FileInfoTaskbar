#pragma once

#include "TaskbarHandler.h"

#include <retroshare/rsplugin.h>

class FileInfoTaskbarPlugin: public RsPlugin
{
public:
	FileInfoTaskbarPlugin();

	virtual void stop();
	virtual void getPluginVersion(int &major, int &minor, int &build, int &svn_rev) const;
	virtual void setPlugInHandler(RsPluginHandler *pgHandler);
	virtual std::string getShortPluginDescription() const;
	virtual std::string getPluginName() const;
	virtual void setInterfaces(RsPlugInInterfaces& interfaces);
	virtual ConfigPage *qt_config_page() const ;

private:
	mutable TaskbarHandler *stbh = nullptr;
	RsPlugInInterfaces mInterfaces;
	mutable RsPluginHandler *mPlugInHandler;
};
