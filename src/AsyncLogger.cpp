#include <cstddef>
#include <mutex>
#include <utility>

#include "AsyncLogger.hpp"

/*----------------------------*/
/*			Ctors/Dtors		  */
/*----------------------------*/

AsyncLogger::AsyncLogger(ILogger *logger) : endRequested_(false)
{
	if (logger != nullptr)
		this->loggers_.push_back(logger);
	this->tLog_ = std::thread(&AsyncLogger::Run, this);
}

AsyncLogger::~AsyncLogger()
{
	{
		std::lock_guard<std::mutex> lock(mtx_);
		endRequested_ = true;
	}
	cv_.notify_all();

	if (tLog_.joinable())
		tLog_.join();

	for (auto logger : loggers_)
		delete logger;
}

/*----------------------------*/
/*			Interface		  */
/*----------------------------*/

void	AsyncLogger::Log(const std::string &message, int level)
{
	std::lock_guard<std::mutex> lock(this->mtx_);
	this->msgs_.push_back(message);
	this->levels_.push_back(level);
	this->cv_.notify_all();
}

void	AsyncLogger::SetMinLevel(int level)
{
	std::lock_guard<std::mutex> lock(mtx_);
	for (auto logger : loggers_)
		if (logger)
			logger->SetMinLevel(level);
}

/*--------------------------------*/
/*			Public Methods		  */
/*--------------------------------*/

void	AsyncLogger::AddLogger(ILogger *logger)
{
	if (!logger)	return ;
	std::lock_guard<std::mutex> lock(this->mtx_);
	this->loggers_.push_back(logger);
}


/*--------------------------------*/
/*			Private Methods		  */
/*--------------------------------*/

void	AsyncLogger::Run()
{
	while (true)
	{
		std::unique_lock<std::mutex> lock(this->mtx_);

		// this->cv_.wait(lock, [this]() { return !this->msgs_.empty() || this->endRequested_; });	  // version lambda a approfondir avant de mettre dans le code (je comprend r)
		while (this->msgs_.empty() && !endRequested_)
			this->cv_.wait(lock);

		if (this->endRequested_ && this->msgs_.empty())
			break ;

		//trick malin copy avant d'ecrire pour liberer le mutex avant la double boucle, ajoute une legere l'attente pour le disp mais bloque bcp moins
		std::deque<std::string>	currMsgs = std::move(this->msgs_);
		std::deque<int>	currLvls = std::move(this->levels_);
		lock.unlock();

		for (size_t i=0; i < currMsgs.size(); i++)
		{
			for (size_t j=0; j < this->loggers_.size(); j++)
			{
				if (this->loggers_[j])
					this->loggers_[j]->Log(currMsgs[i], currLvls[i]);
			}
		}
	}
}
