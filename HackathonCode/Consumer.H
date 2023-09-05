#ifndef CONSUMER_H
#define CONSUMER_H
#include <queue>

class Consumer
{
    public:
        bool Consume();
        void ConsumeAll();
        void Feed(const int i);
    private:
        bool IsNotConsumable(const int& n);
    private:
        std::queue<int> _iQueue;
};

#endif // CONSUMER_H
