#ifndef PRODUCER_H
#define PRODUCER_H

class Consumer;

class Producer
{
    public:
        Producer(Consumer* c);
        void ProduceN(const int& num = 0);
    private:
        Consumer* _consumer;
};

#endif // PRODUCER_H
