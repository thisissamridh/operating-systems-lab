#include <iostream>
using namespace std;

// making a structure for the process that has name , arrival time , burst time , completion time , waiting time , turn around time , normalized turn around time and a variable to check if the process is completed or not
struct process
{
    char name;
    int at, bt, ct, wt, tt;
    int completed;
    float ntt;
} p[10]; // here max number of processes is 10
int n;   // number of processes

void sortByArrival() // here we are sorting the processes according to their arrival time
{
    struct process temp;
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].at > p[j].at)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}
// here we are taking input from the user
{
    struct process temp; // here we are making a temporary variable of the structure process
    //  to swap the processes according to their arrival time
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].at > p[j].at)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

int main()
{
    int i, j, sum_bt = 0;
    cin >> n;
    char c;
    float t, avgwt = 0, avgtt = 0; // setting initial values of average waiting time and average turn around time to 0
    int arriv[n];                  // array to store arrival time of processes

    for (int i = 0; i < n; i++)
    {
        cout << "enter arrival time of process " << i + 1 << ":";
        cin >> arriv[i];
    }
    int burst[n]; // array to store burst time of processes
    for (int i = 0; i < n; i++)
    {
        cout << "enter burst time of process " << i + 1 << ":";
        cin >> burst[i];
    }

    for (i = 0, c = 'A'; i < n; i++, c++)
    {
        p[i].name = c;
        p[i].at = arriv[i];
        p[i].bt = burst[i];
        p[i].completed = 0;
        sum_bt += p[i].bt;
    }

    sortByArrival();
    cout << "PN\tAT\tBT\tWT\tTAT\tNTT";
    for (t = p[0].at; t < sum_bt;)
    {
        float hrr = -9999; // setting initial value of hrr to -9999
        float temp;
        int loc; // location of the process with highest hrr
        for (i = 0; i < n; i++)
        {
            if (p[i].at <= t && p[i].completed != 1)
            {
                temp = (p[i].bt + (t - p[i].at)) / p[i].bt; // calculating the hrr
                if (hrr < temp)
                {
                    hrr = temp;
                    loc = i; // storing the location of the process with highest hrr
                }
            }
        }
        t += p[loc].bt;
        p[loc].wt = t - p[loc].at - p[loc].bt;
        p[loc].tt = t - p[loc].at;
        avgtt += p[loc].tt;
        p[loc].ntt = ((float)p[loc].tt / p[loc].bt); // calculating the normalized turn around time

        p[loc].completed = 1;

        avgwt += p[loc].wt;
        cout << "\n"
             << p[loc].name << "\t" << p[loc].at;
        cout << "\t" << p[loc].bt << "\t" << p[loc].wt;
        cout << "\t" << p[loc].tt << "\t" << p[loc].ntt;
    }
    cout << "\nAverage waiting time: " << avgwt / n << endl;
    cout << "Average Turn Around time:" << avgtt / n;
}