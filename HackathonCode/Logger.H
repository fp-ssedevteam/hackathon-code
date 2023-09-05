#ifndef LOGGER_H
#define LOGGER_H

class Logger
{
public:
    enum LogLevel {
        LL_DEBUG = 0,
        LL_ERROR
    };

    static Logger* Instance();

    ~Logger();
    
    void LogMessage(const LogLevel& level, const std::string msg);

private:
    Logger() {
    }
    static Logger* _myInstance;
};

#endif // LOGGER_H