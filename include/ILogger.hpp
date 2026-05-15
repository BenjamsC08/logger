#ifndef ILOGGER_HPP
# define ILOGGER_HPP

# include <string>

class ILogger
{
public:
	virtual	~ILogger() {};
	virtual void	Log(const std::string &message, int level) = 0; // level: 0=info, 1=Warning, 2=Error
	virtual void	SetMinLevel(int level) = 0;
};

#endif
