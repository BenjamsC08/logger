#include "AsyncLogger.hpp"
#include "def.hpp"
#include <mutex>

AsyncLogger::AsyncLogger(ILogger *logger) : endRequested_(false)
{
	this->loggers_.push_back(logger);
}

AsyncLogger::~AsyncLogger()
{
	std::lock_guard<std::mutex> lock(this->mtxMsg_);
	this->endRequested_ = true;
	this->tLog_.join();
	for (t_uint i=0; i < this->loggers_.size(); i++)
	{
		delete this->loggers_[i];
	}
}

/*			Interface		  */
void	AsyncLogger::Log(const std::string &message, int level)
{
	std::lock_guard<std::mutex> lock(this->mtxMsg_);
	this->msgs_.push_back(message);
	this->levels_.push_back(level);
	this->cv_.notify_all();
}

void	AsyncLogger::SetMinLevel(int level)
{	(void)level;	}

void	AsyncLogger::AddLogger(ILogger *logger)
{
	//mutex 2
	std::lock_guard<std::mutex> lock(this->mtxLog_);
	this->loggers_.push_back(logger);
	//unmutex 2
}

void	AsyncLogger::Run()
{
	std::unique_lock<std::mutex> lockLog(this->mtxLog_);
	std::unique_lock<std::mutex> lock(this->mtxMsg_);
	while (this->msgs_.empty() && !this->endRequested_)
		this->cv_.wait(lock);

}
