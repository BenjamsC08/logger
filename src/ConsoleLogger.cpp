#include <iostream>
#include <ostream>

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
		case 0:
			start = GRAY;
			start += "[DEBUG] ";
			break;
		case 1:
			start = CYAN;
			start += "[INFO] ";
			break;

		case 2:
			start = YELLOW;
			start += "[WARN] ";
			break;
		case 3:
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
	

