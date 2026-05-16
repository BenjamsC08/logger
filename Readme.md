# Logger

## How to use
### code
you need to create a Logger i have coded 3 types of them:
- ConsoleLogger 
- FileLogger
- AsyncLogger

you actually can manage multiple Logger like ones only in **AsyncLogger** with the *AddLogger* methods of it.

4 levels of Logs **DEBUG**, **INFO**, **WARN**, **ERROR**
#### Exemple
```
int main()
{
/* 
*  first param for Console and File Logger is the path/ostream 
*  the 2nd one is the min level manage by this logger,
*  by default min level is 0 (DEBUG)
*/

// AsyncLogger only take *ILogger and need to be destroy with delete

	AsyncLogger* asyncLog = new AsyncLogger(
        new ConsoleLogger(std::cerr)
    );
	asyncLog->AddLogger(new FileLogger("app.log", 1));


	asyncLog->Log("Test async DEBUG", DEBUG);
	asyncLog->Log("Test async WARN", WARN);

	delete asyncLog;
	return 0;
}
```
### import
- Clone the project
- Compile with make commands
- copy the liblog.a and include/Logger.hpp to your project
- if you use a Makefile need to add the .hpp file to your includes (-I), the libpath with -L and the libname with -l

## Why i've doing this
After trying to use **s&box editor** from **facepunch**, and see a lot of Interfaces usage, i wanna learned interface in cpp. So i ask an llm to give me some exercices and i found some interesting, like this one.
