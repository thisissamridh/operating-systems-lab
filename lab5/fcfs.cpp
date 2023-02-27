#include <iostream>

using namespace std;

int main()
{
    int n; // number of processes
    cout << "Enter the number of processes: ";
    cin >> n;
t bt[n], at[n], wt[n], tat[n], ct[n]; // burst time , arrival time , waiting time , turn around time , completion time
    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> at[i] >> bt[i]; // here we are taking the input of arrival time and burst time
    }

    int currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        if (currentTime < at[i])
        {                        // if the arrival time is larger than the current time then we will take it as the arrival time
            currentTime = at[i]; // we will update the current time as the new arrival time
        }
        ct[i] = currentTime + bt[i]; //
        tat[i] = ct[i] - at[i]; // turn around time = completion time - arrival time
        wt[i] = tat[i] - bt[i]; // waiting time = turn around time - burst time
        currentTime = ct[i]; // we will update the current time as the completion time
    }

    double totalWaitingTime = 0.0, totalTurnAroundTime = 0.0;
    for (int i = 0; i < n; i++)
    {
        totalWaitingTime += wt[i];
        totalTurnAroundTime += tat[i];
    }

    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t" << at[i] << "\t\t" << bt[i] << "\t\t" << ct[i] << "\t\t" << tat[i] << "\t\t\t" << wt[i] << endl;
    }

    cout << "\nAverage Turn Around Time: " << totalTurnAroundTime / n << endl;
    cout << "Average Waiting Time: " << totalWaitingTime / n << endl;

    return 0;
}