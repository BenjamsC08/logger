
#include "AsyncLogger.hpp"
#include "ConsoleLogger.hpp"
#include "FileLogger.hpp"
#include "ILogger.hpp"

int main()
{
	AsyncLogger* asyncLog = new AsyncLogger(new ConsoleLogger(std::cerr));
	asyncLog->AddLogger(new FileLogger("app.log", 1));

	asyncLog->Log("Test async DEBUG", DEBUG);
	asyncLog->Log("Test async WARN", WARN);

	delete asyncLog;
	return 0;
}
