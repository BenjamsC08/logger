#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <condition_variable>
# include <deque>
# include <fstream>
# include <iostream>
# include <mutex>
# include <string>
# include <thread>
# include <vector>

enum Level
{
	DEBUG	= 0,
	INFO	= 1,
	WARN	= 2,
	ERROR	= 3
};

/*
 *
 *		  INTERFACE
 *
 */

class ILogger
{
public:
	virtual			~ILogger() {};
	virtual void	Log(const std::string &message, int level) = 0;
	virtual void	SetMinLevel(int level) = 0;
};


/*
 *
 *		  CONSOLE LOG
 *
 */

class ConsoleLogger : public ILogger
{
public:
	/*			Ctors/Dtors		  */
	/*			Removed		  */
	ConsoleLogger() = delete;
	ConsoleLogger &operator=(const ConsoleLogger &) = delete;
	ConsoleLogger(const ConsoleLogger &) = delete;
	/*			Active		  */
	explicit ConsoleLogger(std::ostream &stream = std::cout, int minLvl = 0);
	virtual ~ConsoleLogger();

	/*			Interface		  */
	virtual void	Log(const std::string &, int );
	virtual void	SetMinLevel(int);


private:
	std::ostream  &os_;
	int			  minLevel_;

};


/*
 *
 *		  FILE LOG
 *
 */

class FileLogger : public ILogger
{
public:
	/*			Ctors/Dtors		  */
	/*			Removed		  */
	FileLogger() = delete;
	FileLogger(const FileLogger &) = delete;
	FileLogger &operator=(const FileLogger &) = delete;

	/*			Removed		  */
	explicit FileLogger(std::string filePath, int minLvl = 0);
	virtual ~FileLogger();

	/*			Interface		  */
	virtual void	Log(const std::string &, int);
	virtual void	SetMinLevel(int);

private:
	std::ofstream	ofs_;
	int				minLvl_;

};


/*
 *
 *		  ASYNC LOG
 *
 */

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
