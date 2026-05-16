
#include "AsyncLogger.hpp"
#include "ConsoleLogger.hpp"
#include "FileLogger.hpp"
#include "ILogger.hpp"
#include "LoggerFactory.hpp"

int main1()
{
	auto logger = CreateLogger("stderr");

	logger->Log("ceci est un test0", DEBUG);
	logger->Log("ceci est un test1", INFO);
	logger->Log("ceci est un test2", WARN);
	logger->Log("ceci est un test3", ERROR);


	auto logger1 = CreateLogger("file", "test.log", 1);

	logger1->Log("ceci est un test0", DEBUG);
	logger1->Log("ceci est un test1", INFO);
	logger1->Log("ceci est un test2", WARN);
	logger1->Log("ceci est un test3", ERROR);

	return 0;
}



int main()
{
	// ILogger* console = new ConsoleLogger();
	// ILogger* file    = new FileLogger("app.log", 1);
	
	AsyncLogger* asyncLog = new AsyncLogger(new ConsoleLogger(std::cerr));
	asyncLog->AddLogger(new FileLogger("app.log", 1));


	asyncLog->Log("Test async DEBUG", DEBUG);
	asyncLog->Log("Test async WARN", WARN);
	// asyncLog->SetMinLevel(WARN);

	delete asyncLog;
	return 0;
}
