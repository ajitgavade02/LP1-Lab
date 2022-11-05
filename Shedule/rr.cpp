#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout << "\t----Round Robin (RR) implementation ----\t\n";
    int t;
    cout << "\nenter number of tasks : ";
    cin >> t;

    int ts;
    cout << "\nenter time slot :";
    cin >> ts;
    int bt[t];
    int btt[t];
    int ct[t];
    int sum = 0;
    for (int i = 0; i < t; i++)
    {
        cout << "enter brust time for process no." << i + 1 << " : ";
        cin >> bt[i];
        btt[i] = bt[i];
        sum += bt[i];
    }
    int sum1 = 0;
    while (1)
    {
        if (sum1 == sum)
        {
            break;
        }
        for (int i = 0; i < t; i++)
        {
            if (bt[i] != 0)
            {
                if (bt[i] >= ts)
                {
                    bt[i] -= ts;
                    sum1 += ts;
                    if (bt[i] == 0)
                    {
                        ct[i] = sum1;
                    }
                }
                else
                {
                    sum1 += bt[i];
                    bt[i] = 0;
                    ct[i] = sum1;
                }
            }
        }
    }
    int tat[t];
    int wt[t];
    int sum3 = 0;
    int sum4 = 0;
    for (int i = 0; i < t; i++)
    {
        tat[i] = ct[i];
        wt[i] = tat[i] - btt[i];
        sum3 += wt[i];
        sum4 += tat[i];
    }
    cout << "\n------------------------------------------------\n";
    cout << "TASK\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < t; i++)
    {
        cout << i + 1 << "\t" << 0 << "\t" << btt[i] << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
    }

    cout << "\n";
    cout << "Average waiting time is : ";
    cout << sum3 / ((double)t) << "\n";
    cout << "\n";
    cout << "Average TAT is :";
    cout << sum4 / (double(t)) << "\n";
}
