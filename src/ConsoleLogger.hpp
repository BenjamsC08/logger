#ifndef CONSOLELOGGER_HPP
# define CONSOLELOGGER_HPP

# include <iostream>

# include "ILogger.hpp"

class ConsoleLogger : public ILogger
{
public:
	explicit ConsoleLogger(std::ostream &stream = std::cout, int minLvl = 0);
	ConsoleLogger(const ConsoleLogger &) = delete;
	ConsoleLogger &operator=(const ConsoleLogger &) = delete;

	virtual ~ConsoleLogger();

	virtual void	Log(const std::string &, int );
	virtual void	SetMinLevel(int);


private:
	std::ostream  &os_;
	int			  minLevel_;

};

#endif
