#ifndef LOGGER
#define LOGGER

#include <iostream>
#include <sstream>
#include <mutex>

enum LogLevel { DEBUG, VERB2, VERB1, INFO, WARN, ERROR};
static const char *logStrings[] =
    { "DEBUG", "VERB2", "VERB1", "INFO ", "WARN ", "ERROR" };

const LogLevel logLevel = WARN;

class logIt {
    LogLevel level;
public:
    logIt(LogLevel l);
    logIt(LogLevel l, const char *s);

    template <typename T>
    logIt & operator<<(T const & value) {
        //_buffer << value;
        return *this;
    }

    ~logIt();

private:
    static std::ostringstream _buffer;
    bool toPrint;
    static std::mutex llock;
};

#define GET_MACRO(_1,_2,NAME,...) NAME
#define logger(...) GET_MACRO(__VA_ARGS__, logIt, logIt)(__VA_ARGS__)

#endif
