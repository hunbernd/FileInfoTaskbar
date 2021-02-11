#include "FileInfoTaskbarSettings.h"
#include "TaskbarHandler.h"

#include <QApplication>
#include <QWidget>

TaskbarHandler::TaskbarHandler(FileInfoTaskbarConfig *parent) : QObject(parent)
{
	configPage = parent;
	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &TaskbarHandler::tick);
}

void TaskbarHandler::start(RsFiles *files)
{
	mFiles = files;
	timer->start(1000);
}

void TaskbarHandler::stop()
{
	timer->stop();
	progressbar->hide();
}

bool TaskbarHandler::checkWindow()
{
	if(haswWindow) return true;

	QWidget *window = configPage->window();
	if(window){
		//std::cout << "Window title: "<< window->windowTitle().toStdString() << std::endl;
		if(window->windowHandle()){
			button = new QWinTaskbarButton(window);
			button->setWindow(window->windowHandle());
			progressbar = button->progress();
			progressbar->setRange(0, 100);
			haswWindow = true;
		} else {
			std::cout << "error TaskbarHandler no window found" << std::endl;
		}
	} else {
		std::cout << "error TaskbarHandler no parent widget found" << std::endl;
	}

	return haswWindow;
}

void TaskbarHandler::setProgress(int color, int percent)
{
	if(color == TaskbarColors::None){
		progressbar->hide();
	} else {
		if(color == TaskbarColors::Green){
			progressbar->resume();
		} else if(color == TaskbarColors::Yellow){
			progressbar->pause();
		} else if(color == TaskbarColors::Red){
			progressbar->stop();
		}
		progressbar->setValue(percent);
		progressbar->show();
	}
}

void TaskbarHandler::tick()
{
	if(!checkWindow()) return;

	FileInfoTaskbarSettings *settings = configPage->getSettings();

	std::list<RsFileHash> hashes;
	mFiles->FileDownloads(hashes);

	int all = 0;
	int completed = 0;
	int downloading = 0;
	uint64_t allbytes = 0;
	uint64_t completedbytes = 0;
	for(auto hash : hashes){
		FileInfo info;
		if(rsFiles->FileDetails(hash, RS_FILE_HINTS_DOWNLOAD, info)){
			all++;
			allbytes += info.size;
			completedbytes += info.avail;
			//std::cout << "Downloading file " << info.fname << " " << info.downloadStatus << std::endl;
			if(info.downloadStatus == FT_STATE_COMPLETE){
				completed++;
			} else if(info.downloadStatus == FT_STATE_DOWNLOADING){
				downloading++;
			}
		}
	}

	if(all == 0){
		setProgress(TaskbarColors::None, 0);
	} else if(all == completed) {
		setProgress(settings->allfinishedcolor, 100);
	} else {
		int percent = settings->bytes ? ((int)(completedbytes * 100 / allbytes)) : ((int)(completed * 100 / all));
		if(downloading > 0){
			setProgress(settings->activecolor, percent);
		} else { //Nothing is downloading, some files stuck
			setProgress(settings->stuckcolor, percent);
		}
	}
}
