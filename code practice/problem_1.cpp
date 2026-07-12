// 1. A university system generates student IDs using a shared variable next_id.
// When multiple admission requests are processed simultaneously, some students receive duplicate
// IDs. No synchronization mechanism is currently used. Implement a C++ program demonstrating
// this issue



#include<bits/stdc++.h>
using namespace std;

int next_id = 1;

void generateID(int student)
{
    int id = next_id; 

    this_thread::sleep_for(chrono::milliseconds(50)); 

    next_id = id + 1; 

    cout << "Student " << student
         << " got ID: " << id << endl;
}

int main()
{
    vector<thread> students;

    for (int i = 1; i <= 10; i++)
    {
        students.push_back(thread(generateID, i));
    }

    for (auto &t : students)
    {
        t.join();
    }

    cout << "\nFinal next_id = " << next_id << endl;

    return 0;
}