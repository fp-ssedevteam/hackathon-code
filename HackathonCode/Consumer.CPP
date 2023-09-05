#include <iostream>
#include <sstream>
#include "Consumer.H"
#include "Logger.H"

bool Consumer::IsNotConsumable(const int& n)
{
    // Corner case
    if (n <= 1)
        return false;
 
    // Check from 2 to n-1
    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return false;
 
    return true;
}

void Consumer::Feed(const int i) {
    _iQueue.push(i);
}

bool Consumer::Consume() {
    std::stringstream sMsg;
    Logger::LogLevel level;

    if (_iQueue.front() <= 0) {
        return false;
    }

    sMsg << "Consuming " << _iQueue.front() << ". ";

    if (IsNotConsumable(_iQueue.front())) {
        sMsg << "Cannot consume this Number." << std::endl;
        level = Logger::LL_ERROR;
    } else {
        sMsg << "Consumed successfully!";
        level = Logger::LL_DEBUG;
    }

    Logger::Instance()->LogMessage(level, sMsg.str());
    
    _iQueue.pop();
    return true;
}

void Consumer::ConsumeAll() {
    while (_iQueue.size() > 0) {
        Consume();
    }
}
