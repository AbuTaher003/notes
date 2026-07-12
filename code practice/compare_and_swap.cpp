#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <atomic> 

using namespace std;

int next_id = 1;
atomic<int> lock_var(0);

int compare_and_swap(atomic<int> *value, int expected, int new_value)
{
    int temp = value->load(); 
    
    int exp = expected; 
    value->compare_exchange_strong(exp, new_value);
    
    return temp; 
}

void generate_id(int i)
{
    while (compare_and_swap(&lock_var, 0, 1) != 0)
    {
    }

    int temp = next_id;
    this_thread::sleep_for(chrono::milliseconds(10));
    next_id = temp + 1;

    cout << "Thread " << i << " Assigned ID: " << temp << "\n";

    lock_var.store(0); 
}

int main()
{
    vector<thread> threads;

    for (int i = 0; i < 10; i++)
    {
        threads.emplace_back(generate_id, i);
    }

    for (auto &t : threads)
    {
        t.join();
    }

    return 0;
}
