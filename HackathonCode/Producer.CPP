#include <iostream>
#include <sstream>
#include "Producer.H"
#include "Consumer.H"
#include "Logger.H"

Producer::Producer(Consumer* c) : _consumer(c) {
}

void Producer::ProduceN(const int& num) {
    srand(time(0));

    for (int i = 0; i < num; ++i) {
        int generatedNum(rand());
        std::stringstream sMsg;
        sMsg << "Feeding " << generatedNum;
        Logger::Instance()->LogMessage(Logger::LL_DEBUG, sMsg.str());
        _consumer->Feed(generatedNum);
    }
}
