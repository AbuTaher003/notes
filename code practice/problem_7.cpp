// 7. A factory has:
// • Producers adding items
// • Consumers removing items
// Rules:
// • Buffer size is limited
// • Producers must wait if full
// • Consumers must wait if empty
// Tasks
// 1. Identify synchronization tool
// 2. Implement in C++



#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 5;
queue<int> buffer;
mutex mtx;
condition_variable cv;
void produce(int id)
{
    for (int i = 0; i < 10; i++)
    {
        unique_lock<mutex> lock(mtx);
        while (buffer.size() == MAX_SIZE)
        {
            cv.wait(lock);
        }
        buffer.push(i);
        cout << "Producer " << id << " produced " << i << endl;

        cv.notify_all();
    }
}

void consume(int id)
{
    for (int i = 0; i < 10; i++)
    {
        unique_lock<mutex> lock(mtx);

        while (buffer.empty())
        {
            cv.wait(lock);
        }

        int item = buffer.front();
        buffer.pop();

        cout << "Consumer " << id << " consumed " << item << endl;

        cv.notify_all();
    }
}

int main()
{
    thread p1(produce, 1);
    thread c1(consume, 1);

    p1.join();
    c1.join();

    return 0;
}