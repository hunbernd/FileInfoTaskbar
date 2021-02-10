#include "TaskbarHandler.h"

#include <QApplication>
#include <QWidget>

TaskbarHandler::TaskbarHandler(QWidget *parent) : QObject(parent)
{
	std::cout << "error StatusbarHandler ctor begin" << std::endl;
	configPage = parent;
	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &TaskbarHandler::tick);
	std::cout << "error StatusbarHandler ctor end" << std::endl;
}

void TaskbarHandler::start(RsFiles *files)
{
	std::cout << "error StatusbarHandler start" << std::endl;
	mFiles = files;
	timer->start(1000);
}

void TaskbarHandler::stop()
{
	std::cout << "error StatusbarHandler stop" << std::endl;
	timer->stop();
	progressbar->hide();
}

bool TaskbarHandler::checkWindow()
{
	std::cout << "error StatusbarHandler checkWindow begin" << std::endl;
	if(haswWindow) return true;
	std::cout << "error StatusbarHandler checkWindow 1" << std::endl;

	QWidget *window = configPage->window();
	if(window){
		std::cout << "error StatusbarHandler checkWindow 2" << std::endl;
		std::cout << "error Window title: "<< window->windowTitle().toStdString() << std::endl;
		if(window->windowHandle()){
			std::cout << "error StatusbarHandler checkWindow 3" << std::endl;
			button = new QWinTaskbarButton(window);
			button->setWindow(window->windowHandle());
			progressbar = button->progress();
			progressbar->setRange(0, 100);
			haswWindow = true;
			std::cout << "error StatusbarHandler checkWindow 4" << std::endl;
		} else {
			std::cout << "error no window" << std::endl;
		}
	} else {
		std::cout << "error no parent widget" << std::endl;
	}

	std::cout << "error StatusbarHandler checkWindow end" << std::endl;
	return haswWindow;
}

void TaskbarHandler::tick()
{
	std::cout << "error StatusbarHandler tick begin" << std::endl;
	if(!checkWindow()) return;
	std::cout << "error StatusbarHandler tick 1" << std::endl;

	std::list<RsFileHash> hashes;
	mFiles->FileDownloads(hashes);

	int all = 0;
	int completed = 0;
	uint64_t allbytes = 0;
	uint64_t completedbytes = 0;
	for(auto hash : hashes){
		FileInfo info;
		if(rsFiles->FileDetails(hash, RS_FILE_HINTS_DOWNLOAD, info)){
			all++;
			allbytes += info.size;
			completedbytes += info.avail;
			if(info.downloadStatus==FT_STATE_COMPLETE){
				completed++;
			}
		}
	}

	std::cout << "error StatusbarHandler tick 2" << std::endl;

	if(all == 0){
		progressbar->hide();
		std::cerr << "No downloads" << std::endl;
	} else {
		progressbar->show();
		//taskbar->setValue((int)((float)completed / (float)all * 100));
		//progressbar->setValue(50);
		//progressbar->setValue(completed * 100 / all);
		progressbar->setValue((int)(completedbytes * 100 / allbytes));
		progressbar->resume();
		std::cerr << "Downloads completed: " << completedbytes << "/" << allbytes << std::endl;
	}

	std::cout << "error StatusbarHandler tick end" << std::endl;
}
