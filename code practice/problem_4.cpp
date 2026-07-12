// 4. A bank has implemented an ATM system where multiple users can access their accounts
// simultaneously. Each transaction updates a shared variable called balance.
// Recently, the bank noticed that sometimes the balance becomes incorrect when multiple users
// withdraw or deposit money at the same time.
// The system designer decides to use a low-level hardware-supported locking mechanism where:
// • A lock variable is checked and set in one atomic step
// • Threads repeatedly check the lock until it becomes free
// Tasks
// 1. Identify the synchronization technique used
// 2. Write a C++ program to solve this problem


#include<bits/stdc++.h>
using namespace std;

int balance = 1000;              
// atomic<bool> lock_var(false);
bool lock_var = false;   

bool test_and_set(bool *target) {
    // return lock_var.exchange(true);
     bool rv = *target;
    *target = true;
    return rv;
}

void acquire_lock() {
    while (test_and_set(&lock_var)) {
    }
}

void release_lock() {
    lock_var = false;
}

void transaction(int id, int amount) {
    acquire_lock();

    if (amount < 0 && balance + amount < 0) {
        cout << "Thread " << id << " Withdrawal failed (Insufficient balance)\n";
    } else {
        balance += amount;
        cout << "Thread " << id << " Updated balance: " << balance << endl;
    }

    release_lock();
}

int main() {
    vector<thread> threads;

    threads.push_back(thread(transaction, 1, -200));
    threads.push_back(thread(transaction, 2, -500));
    threads.push_back(thread(transaction, 3, 300));
    threads.push_back(thread(transaction, 4, -700));
    threads.push_back(thread(transaction, 5, 200));

    for (auto &t : threads) {
        t.join();
    }

    cout << "\nFinal Balance: " << balance << endl;

    return 0;
}