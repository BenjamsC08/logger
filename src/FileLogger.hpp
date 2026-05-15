#ifndef FILELOGGER_HPP
# define FILELOGGER_HPP

#include "ILogger.hpp"
#include <fstream>
#include <string>

class FileLogger : public ILogger
{
public:
	/*			Ctors/Dtors		  */
	/*			Removed		  */
	FileLogger() = delete;
	FileLogger(const FileLogger &) = delete;
	FileLogger &operator=(const FileLogger &) = delete;

	/*			Removed		  */
	explicit FileLogger(std::string filePath, int minLvl = 0);
	virtual ~FileLogger();

	/*			Interface		  */
	virtual void	Log(const std::string &, int);
	virtual void	SetMinLevel(int);

private:
	std::ofstream	ofs_;
	int				minLvl_;

};

#endif
