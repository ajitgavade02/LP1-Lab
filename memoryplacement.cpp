#include <bits/stdc++.h>
using namespace std;

void FirstFit(int n, vector<pair<int, int>> &v)
{
    int z;
    cout << "Enter size of new process :";
    cin >> z;

    for (int i = 0; i < n; i++)
    {
        if (v[i].first >= z && v[i].second == 0)
        {
            v[i].second = z;
            return;
        }
    }
    cout << "Cannot find Memory for : " << z << endl;
}
void BestFit(int n, vector<pair<int, int>> &v)
{
    int z;
    cout << "Enter size of new process :";
    cin >> z;
    int mn = 1000000;
    for (int i = 0; i < n; i++)
    {
        if (v[i].first >= z && v[i].second == 0)
        {
            mn = min(mn, v[i].first);
        }
    }
    if (mn == 1000000)
    {
        cout << "Cannot find Memory for : " << z << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i].first == mn && v[i].second == 0)
            {
                v[i].second = z;
                return;
            }
        }
    }
}

void WorstFit(int n, vector<pair<int, int>> &v)
{
    int z;
    cout << "Enter size of new process :";
    cin >> z;
    int mx = -1;
    for (int i = 0; i < n; i++)
    {
        if (v[i].first >= z && v[i].second == 0)
        {
            mx = max(mx, v[i].first);
        }
    }
    if (mx == -1)
    {
        cout << "Cannot find Memory for : " << z << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i].first == mx && v[i].second == 0)
            {
                v[i].second = z;
                return;
            }
        }
    }
}

int main()
{
    cout << "Enter no. of memory spaces : ";
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter size :";
        int sz;
        cin >> sz;
        v.push_back({sz, 0});
    }
    while (1)
    {
        int ch;
        cout << "Enter choices :" << endl;
        cout << "1.First fit" << endl;
        cout << "2.Best fit" << endl;
        cout << "3.Worst fit" << endl;
        cin >> ch;
        if (ch == 1)
        {
            FirstFit(n, v);
            cout << "Memory:    ";
            for (auto x : v)
            {
                cout << x.first << "\t";
            }
            cout << endl;
            cout << "Allocated: ";
            for (auto x : v)
            {
                cout << x.second << "\t";
            }
            cout << endl;
        }
        else if (ch == 2)
        {
            BestFit(n, v);
            cout << "Memory:    ";
            for (auto x : v)
            {
                cout << x.first << "\t";
            }
            cout << endl;
            cout << "Allocated: ";
            for (auto x : v)
            {
                cout << x.second << "\t";
            }
            cout << endl;
        }
        else if (ch == 3)
        {
            WorstFit(n, v);
            cout << "Memory:    ";
            for (auto x : v)
            {
                cout << x.first << "\t";
            }
            cout << endl;
            cout << "Allocated: ";
            for (auto x : v)
            {
                cout << x.second << "\t";
            }
            cout << endl;
        }
        else
        {
            cout << "Enter valid choice !" << endl;
        }
        cout << "Do you want to continue (0/1)";
        int ask;
        cin >> ask;
        if (ask == 0)
        {
            break;
        }
    }
}