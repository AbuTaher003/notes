// 3. A file system allows multiple threads to write logs.
// To prevent corruption:
// • Only one thread should write at a time
// • Others should wait efficiently (no busy spinning)
// Implement using C++




#include<bits/stdc++.h>
using namespace std;

mutex m;

void write_log(int i)
{
    unique_lock<mutex> lock(m);

    cout << "Thread " << i << " is writing log..." << endl;

    this_thread::sleep_for(chrono::milliseconds(100));

    cout << "Thread " << i << " finished writing" << endl;

}

int main()
{
    vector<thread> threads;

    for (int i = 0; i < 5; i++)
    {
        threads.push_back(thread(write_log, i));
    }

    for (auto &t : threads)
    {
        t.join();
    }

    return 0;
}