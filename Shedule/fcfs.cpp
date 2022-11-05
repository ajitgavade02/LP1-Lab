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
    //	user input
    for (int i = 0; i < t; i++)
    {
        cout << "Enter arrival time for task no." << i + 1 << " :";
        cin >> AT[i];
        cout << "Enter brust time for task no. " << i + 1 << " :";
        cin >> BT[i];
        mp[AT[i]] = BT[i];
        cout << "\n";
    }
    //	array declaration for CT , TAT and WT;
    int CT[t], TAT[t], WT[t];
    for (auto x : mp)
    {
        CT[0] = x.first + x.second;
        break;
    }
    //	calculating CT,TAT and WT
    int cnt = 0;
    for (auto x : mp)
    {
        if (cnt > 0)
        {
            CT[cnt] = max(CT[cnt - 1], x.first) + x.second;
        }
        cnt++;
    }
    int sum = 0;
    int sum1 = 0;
    for (int i = 0; i < t; i++)
    {
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];
        sum = sum + WT[i];
        sum1 = sum1 + TAT[i];
    }
    cout << "------------------------------------------------\n";
    cout << "TASK\tAT\tBT\tCT\tTAT\tWT\n";
    cout << "------------------------------------------------\n";
    for (int i = 0; i < t; i++)
    {
        cout << i << "\t" << AT[i] << "\t" << BT[i] << "\t" << CT[i] << "\t" << TAT[i] << "\t" << WT[i] << "\n";
    }
    cout << "------------------------------------------------\n";
    //	average
    cout << "\nAverage waiting time is :\n";
    cout << sum / (double)t;
    cout << "\n";
    cout << "\nAverage TAT is:\n";
    cout << sum1 / (double)t;
    cout << "\n";
    int sum4 = 0;
    for (int i = 0; i < t; i++)
    {
        sum4 = sum4 + BT[i];
    }
    cout << "\n\nGANTT CHART : \n\n";
    int sum5 = 0;
    int cnt3 = 1;
    for (int i = 0; i < t; i++)
    {
        for (int j = sum5; j < sum5 + BT[i]; j++)
        {
            if (j == sum5 + BT[i] / 2)
            {
                cout << "P" << cnt3;
            }
            else
            {
                cout << " ";
            }
        }
        sum5 = sum5 + BT[i];
        cnt3++;
    }
    cout << "\n";
    for (int i = 0; i < sum4 + t + 1; i++)
    {
        cout << "-";
    }
    cout << "\n";
    for (int i = 0; i < t; i++)
    {
        cout << "|";
        for (int j = 0; j < BT[i]; j++)
        {
            cout << " ";
        }
    }
    cout << "|\n";
    for (int i = 0; i < sum4 + t + 1; i++)
    {
        cout << "-";
    }
    cout << "\n";

    int sum3 = 0;
    for (int i = 0; i < t; i++)
    {
        cout << sum3;
        for (int j = 0; j < BT[i]; j++)
        {
            cout << " ";
        }
        sum3 = sum3 + BT[i];
    }
    cout << sum3 << "\n";
}