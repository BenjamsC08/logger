#ifndef FILELOGGER_HPP
# define FILELOGGER_HPP

#include "ILogger.hpp"
#include <fstream>
#include <string>

class FileLogger : public ILogger
{
public:
	FileLogger() = delete;
	FileLogger(std::string);
	FileLogger(std::string, int);
	FileLogger(const FileLogger &) = delete;
	virtual ~FileLogger();
	FileLogger &operator=(const FileLogger &) = delete;

	
	virtual void	Log(const std::string &, int);
	virtual void	SetMinLevel(int);
private:
	std::ofstream	ofs_;
	int				minLvl_;

};

#endif
