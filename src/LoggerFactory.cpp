#include <memory>

#include "ConsoleLogger.hpp"
#include "FileLogger.hpp"
#include "ILogger.hpp"
#include "LoggerFactory.hpp"

std::unique_ptr<ILogger> CreateLogger(const std::string &type, const std::string &filePath, int minLevel)
{
	if (type == "console" || type == "stdout" || type == "out")
		return std::unique_ptr<ILogger>(new ConsoleLogger(std::cout, minLevel));

	if (type == "stderr" || type == "err")
		return std::unique_ptr<ILogger>(new ConsoleLogger(std::cerr, minLevel));

	if (type == "file" && !filePath.empty())
        return std::unique_ptr<ILogger>(new FileLogger(filePath, minLevel));

	// if (type == "async" && !filePath.empty())
    //     return std::unique_ptr<ILogger>(new AsyncLogger(filePath, minLevel));

	return std::unique_ptr<ILogger>(new ConsoleLogger(std::cout, minLevel));
}

