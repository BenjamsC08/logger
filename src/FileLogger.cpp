#include <ctime>
#include "FileLogger.hpp"

FileLogger::FileLogger(std::string filePath): ofs_(filePath.c_str(), std::ios::app), minLvl_(0)
{}

FileLogger::FileLogger(std::string filePath, int minLvl): 
	ofs_(filePath.c_str(), std::ios::app), minLvl_(minLvl)
{}

FileLogger::~FileLogger()
{
	if (this->ofs_.is_open())
		this->ofs_.close();
}
	
void	FileLogger::Log(const std::string &message, int level)
{
	if (level < this->minLvl_)
		return ;
	std::time_t now = std::time(NULL);
	char buff[16];
	std::strftime(buff, sizeof(buff),"%y%m%d-%H%M", std::localtime(&now));
	std::string start = std::string(buff);
	switch (level)
	{
		case 0:
			start += " | [DEBUG] ";
			break;
		case 1:
			start += " | [INFO] ";
			break;
		case 2:
			start += " | [WARN] ";
			break;
		case 3:
			start += " | [ERR] ";
			break;
		default:
			start += " | ";
	}
	start += message;
	ofs_ << start << '\n';
}
	
void	FileLogger::SetMinLevel(int lvl)
{	this->minLvl_ = lvl;	}
