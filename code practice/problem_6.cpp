// 6. A computer lab has a single printer shared among many students.
// Rules:
// • Only one student can use the printer at a time
// • If the printer is busy, others must wait
// • Waiting students should not waste CPU (no busy waiting)
// The system designer creates a high-level structure where:
// • Shared variables are hidden
// • Only predefined functions can access the resource
// • Waiting is handled automatically
// Tasks
// 1. Identify the synchronization method
// 2. Write a C++ solution



#include <bits/stdc++.h>
using namespace std;
bool busy = false;
mutex mtx;
condition_variable cv;
void usePrinter(int id)
{
    unique_lock<mutex> lock(mtx);
    while (busy)
    {
        cv.wait(lock);
    }
    busy = true;
    cout << "Student " << id << " is printing..." << endl;
    lock.unlock();
    this_thread::sleep_for(chrono::seconds(2));
    lock.lock();
    cout << "Student " << id << " finished printing." << endl;
    busy = false;
    cv.notify_one();
}
void student(int id)
{
    usePrinter(id);
}
int main()
{
    vector<thread> students;
    for (int i = 1; i <= 5; i++)
    {
        students.push_back(thread(student, i));
    }
    for (auto &t : students)
    {
        t.join();
    }
}