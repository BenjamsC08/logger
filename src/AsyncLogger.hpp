#ifndef ASYNCLOGGER_HPP
# define ASYNCLOGGER_HPP

# include <condition_variable>
# include <deque>
# include <mutex>
# include <string>
# include <thread>
# include <vector>

# include "ILogger.hpp"

class AsyncLogger : public ILogger
{
public:
	/*			Ctors/Dtors		  */
	/*			Removed		  */
	AsyncLogger() = delete;
	AsyncLogger(const AsyncLogger &) = delete;
	AsyncLogger &operator=(const AsyncLogger &) = delete;
	/*			Active		  */
	explicit AsyncLogger(ILogger *);
	virtual ~AsyncLogger();

	/*			Interface		  */
	virtual void	Log(const std::string &message, int level);
	virtual void	SetMinLevel(int level);

	/*			Public Methods		  */
	void	AddLogger(ILogger *);

private:
	/*			Private Methods		  */
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
