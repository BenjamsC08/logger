# Logger

## How to use
### Code
You need to create a `Logger`. I have coded 3 types of them:
- ConsoleLogger (classic one)
- FileLogger    (do what the name suggest)
- AsyncLogger   (thread splitted one)

You can actually manage multiple `Loggers` like one only in **AsyncLogger** with the *AddLogger* methods of it.

4 levels of logs: `DEBUG`, `INFO`, `WARN`, `ERROR`
#### Exemple
```
int main()
{
    /*
    first param for Console and File Logger is the path/ostream
    the 2nd one is the min level managed by this logger,
    by default min level is 0 (DEBUG)
    */

    // AsyncLogger only takes *ILogger and needs to be destroyed with delete

    AsyncLogger* asyncLog = new AsyncLogger (
        new ConsoleLogger(std::cerr));

    asyncLog->AddLogger(new FileLogger("app.log", 1));
    asyncLog->Log("Test async DEBUG", DEBUG);
    asyncLog->Log("Test async WARN", WARN);

    delete asyncLog;
    return 0;
}
```
### Import
- Clone the project
- Compile with `make` commands
- copy the `liblog.a` and `include/Logger.hpp` to your project
- if you use a Makefile need to add the .hpp file to your includes `-I`, the libpath with `-L` and the libname with `-l`

## Why i've doing this
After trying to use **s&box editor** from [**Facepunch**](https://en.wikipedia.org/wiki/Facepunch_Studios), and seeing a lot of Interfaces usage, i wanna learn interfaces in C++. So i asked an LLM to give me some exercises and i found some interesting ones, like this logger.
