
#include "LoggerFactory.hpp"

int main()
{
	auto logger = CreateLogger("console");

	logger->Log("ceci est un test0", DEBUG);
	logger->Log("ceci est un test1", INFO);
	logger->Log("ceci est un test2", WARN);
	logger->Log("ceci est un test3", ERROR);


	auto logger1 = CreateLogger("file", "test.log", 1);

	logger1->Log("ceci est un test0", DEBUG);
	logger1->Log("ceci est un test1", INFO);
	logger1->Log("ceci est un test2", WARN);
	logger1->Log("ceci est un test3", ERROR);

}
