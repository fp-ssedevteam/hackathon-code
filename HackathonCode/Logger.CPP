#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "Logger.H"

Logger* Logger::_myInstance = nullptr;

Logger* Logger::Instance(){
    if (!_myInstance) {
        _myInstance = new Logger();
    }
    return _myInstance;
}

Logger::~Logger() {
    delete _myInstance;
}

void Logger::LogMessage(const LogLevel& level, const std::string msg) {
    std::string finMessage;
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);

    finMessage += "\n";

    std::ostringstream oss;
    oss << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
    finMessage += oss.str();

    switch(level) {
        case LL_DEBUG:
            finMessage += " [DEBUG] ";
            break;
        case LL_ERROR:
            finMessage += " [ERROR] ";
            break;
        default:
            finMessage += " [INFO] ";
    }

    finMessage += msg;

    std::cout << finMessage << std::endl;
}
