
#include "ConsoleLogger.hpp"
#include <ios>

ConsoleLogger::ConsoleLogger(std::string &filePath): file_(filePath.c_str(), std::ios::app), minLevel_(0)
{}

ConsoleLogger::ConsoleLogger(std::string &filePath, int minLvl): 
	file_(filePath.c_str(), std::ios::app), minLevel_(minLvl)
{}
	
// ConsoleLogger::ConsoleLogger(const ConsoleLogger &src)
// {}
//
// ConsoleLogger &ConsoleLogger::operator=(const ConsoleLogger &src)
// {}
	
ConsoleLogger::~ConsoleLogger()
{
	if (this->file_.is_open())
		this->file_.close();
}
	
void	ConsoleLogger::Log(const std::string &message, int level)
{
	if (level < this->minLevel_)
		return ;
	this->file_
}
	
void	ConsoleLogger::SetMinLevel(int lvl)
{}
