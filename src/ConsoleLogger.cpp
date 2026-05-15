#include <iostream>

#include "ConsoleLogger.hpp"
#include "def.hpp"

ConsoleLogger::ConsoleLogger(std::ostream &os, int minLvl): os_(os), minLevel_(minLvl)
{}

ConsoleLogger::~ConsoleLogger()
{}
	
void	ConsoleLogger::Log(const std::string &message, int level)
{
	if (level < this->minLevel_)
		return ;
	std::string start;
	switch (level)
	{
		case DEBUG:
			start = GRAY;
			start += "[DEBUG] ";
			break;
		case INFO:
			start = CYAN;
			start += "[INFO] ";
			break;
		case WARN:
			start = YELLOW;
			start += "[WARN] ";
			break;
		case ERROR:
			start = RED;
			start += "[ERR] ";
			break;
		default:
			start = MAGENTA;
			start += "[No code] ";
			break;
	}
	this->os_ << start << message << RESET << '\n';
}
	
void	ConsoleLogger::SetMinLevel(int lvl)
{	this->minLevel_ = lvl;	}
	

