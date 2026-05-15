
#include "ConsoleLogger.hpp"
#include "FileLogger.hpp"
#include "ILogger.hpp"

int main()
{
	ILogger *logger = new ConsoleLogger(std::cerr, 0);

	logger->Log("ceci est un test0", DEBUG);
	logger->Log("ceci est un test1", INFO);
	logger->Log("ceci est un test2", WARN);
	logger->Log("ceci est un test3", ERROR);

	delete logger;

	logger = new FileLogger("test.log", 1);

	logger->Log("ceci est un test0", DEBUG);
	logger->Log("ceci est un test1", INFO);
	logger->Log("ceci est un test2", WARN);
	logger->Log("ceci est un test3", ERROR);

	delete logger;
}
