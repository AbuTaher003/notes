// 5. A multi-core system maintains a global counter that is updated by multiple threads. The
// system must ensure:
// • The counter is updated only if its current value has not been changed by another thread
// • The update must be atomic
// The system uses a hardware instruction that:
// • Compares a variable with an expected value
// • Updates it only if they match
// Tasks
// 1. Identify the synchronization method
// 2. Implement the solution in C++




#include<bits/stdc++.h>
using namespace std;

atomic<int> counter(0);

int compare_and_swap(atomic<int> *value, int expected, int new_value)
{
    int temp = value->load();

    int exp = expected;
    value->compare_exchange_strong(exp, new_value);

    return temp;
}

void increment(int id)
{
    while (true)
    {
        int old_value = counter.load();
        int new_value = old_value + 1;

       
        if (compare_and_swap(&counter, old_value, new_value) == old_value)
        {
            cout << "Thread " << id
                 << " updated counter to "
                 << new_value << endl;
            break;
        }
    }
}

int main()
{
    vector<thread> threads;

    for (int i = 1; i <= 10; i++)
    {
        threads.push_back(thread(increment, i));
    }

    for (auto &t : threads)
        t.join();

    cout << "\nFinal Counter: " << counter << endl;

    return 0;
}