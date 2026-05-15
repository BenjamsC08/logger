#ifndef CONSOLELOGGER_HPP
# define CONSOLELOGGER_HPP

# include <iostream>

# include "ILogger.hpp"

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

#endif
