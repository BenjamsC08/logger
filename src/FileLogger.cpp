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
	if (level < this->minLvl_)	return ;
	char		buff[32];
	std::string start;

	std::time_t now = std::time(nullptr);
	std::tm tm_buf{};
	localtime_r(&now, &tm_buf);
	std::strftime(buff, sizeof(buff),"%y%m%d-%H%M%S", &tm_buf);

	start = std::string(buff);
	switch (level)
	{
		case DEBUG: start += " | [DEBUG] ";	break;
		case INFO:	start += " | [INFO] ";	break;
		case WARN:	start += " | [WARN] ";	break;
		case ERROR:	start += " | [ERR] ";	break;
		default:	start += " | ";
	}
	ofs_ << start << message << '\n';
}
	
void	FileLogger::SetMinLevel(int lvl)
{	this->minLvl_ = lvl;	}
