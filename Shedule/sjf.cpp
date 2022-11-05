#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cout << "\nEnter the number of tasks :";
    cin >> t;
    cout << "\n";
    //	array declaration for AT and BT;
    map<int, int> mp;
    int AT[t], BT[t];
    for (int i = 0; i < t; i++)
    {
        AT[i] = 0;
        cout << "Enter brust time for task no. " << i + 1 << " :";
        cin >> BT[i];
        cout << "\n";
    }
    for (int i = 0; i < t; i++)
    {
        mp[BT[i]] = i + 1;
    }

    int CT[t], TAT[t], WT[t];
    int sr[t];
    int k = 0;
    for (auto x : mp)
    {
        CT[k] = x.first;
        sr[k] = x.second;
        if (k > 0)
        {
            CT[k] += CT[k - 1];
        }
        k++;
    }
    int sum = 0, sum1 = 0;
    sort(BT, BT + t);
    for (int i = 0; i < t; i++)
    {
        TAT[i] = CT[i];
        sum1 = sum1 + TAT[i];
        WT[i] = TAT[i] - BT[i];
        sum = sum + WT[i];
    }

    cout << "------------------------------------------------\n";
    cout << "TASK\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < t; i++)
    {
        cout << sr[i] << "\t" << AT[i] << "\t" << BT[i] << "\t" << CT[i] << "\t" << TAT[i] << "\t" << WT[i] << "\n";
    }
    cout << "------------------------------------------------\n";
    //	average
    cout << "\nAverage waiting time is :\n";
    cout << sum / (double)t;
    cout << "\n";
    cout << "\nAverage TAT is:\n";
    cout << sum1 / (double)t;
    cout << "\n";
}