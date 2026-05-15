
#include "ConsoleLogger.hpp"
#include "ILogger.hpp"

int main()
{
	ILogger *logger = new ConsoleLogger(std::cerr, 0);

	logger->Log("ceci est un test0", 0);
	logger->Log("ceci est un test1", 1);
	logger->Log("ceci est un test2", 2);
	logger->Log("ceci est un test3", 3);

	delete logger;
}
