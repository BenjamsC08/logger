#ifndef ASYNCLOGGER_HPP
# define ASYNCLOGGER_HPP

#include "ILogger.hpp"
#include <condition_variable>
#include <deque>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
class AsyncLogger : public ILogger
{
public:
	AsyncLogger() = delete;
	explicit AsyncLogger(ILogger *);
	AsyncLogger(const AsyncLogger &) = delete;
	virtual ~AsyncLogger();

	AsyncLogger &operator=(const AsyncLogger &) = delete;
	/*			Interface		  */
	virtual void	Log(const std::string &message, int level);
	virtual void	SetMinLevel(int level);

	void	AddLogger(ILogger *);

private:
	void	Run();

private:
	std::vector<ILogger *>	loggers_;
	std::deque<std::string>	msgs_;
	std::deque<int>			levels_;

	std::thread				tLog_;
	std::mutex				mtx_;
	std::condition_variable	cv_;
	bool					endRequested_;


};

#endif
