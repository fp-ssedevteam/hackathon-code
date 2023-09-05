#include <iostream>
#include <Windows.h>
#include <thread>
#include "Producer.H"
#include "Consumer.H"
#include "Logger.H"

void main() {
    Consumer c;
    Producer p(&c);
    
    p.ProduceN(1000);
    c.ConsumeAll();
    
    Logger::Instance()->LogMessage(Logger::LL_DEBUG, "Consumed all the elements.");
}
