// 2. Two processes update a shared database record.
// The system designer wants a software-only solution (no hardware support) that ensures:
// • Mutual exclusion
// • Fair turn-taking
// Implement the solution in C++




#include<bits/stdc++.h>

using namespace std;

int database_record = 0;

bool flag[2] = {false, false};
int turn = 0;

void enter_critical(int i)
{
    int j = 1 - i;

    flag[i] = true;
    turn = j;

    while (flag[j] && turn == j)
    {
    }
}

void exit_critical(int i)
{
    flag[i] = false;
}

void update_database(int i)
{
    for(int k = 0; k < 5; k++)
    {
        enter_critical(i);

        int temp = database_record;
        this_thread::sleep_for(chrono::milliseconds(50));
        database_record = temp + 1;

        cout << "Process " << i 
             << " updated record to " 
             << database_record << endl;

        exit_critical(i);

    }
}

int main()
{
    thread p1(update_database, 0);
    thread p2(update_database, 1);

    p1.join();
    p2.join();

    cout << "Final database value: " << database_record << endl;

    return 0;
}