#ifndef ILOGGER_HPP
# define ILOGGER_HPP

# include <string>

class ILogger
{
public:
	virtual	~ILogger() {};
	virtual void	Log(const std::string &message, int level) = 0; // level: 0=debug, 1=info, 2=warning, 3=error
	virtual void	SetMinLevel(int level) = 0;
};

enum Level
{
	DEBUG	= 0,
	INFO	= 1,
	WARN	= 2,
	ERROR	= 3
};

#endif
