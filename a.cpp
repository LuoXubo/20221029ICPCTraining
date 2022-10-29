/*
 * @Author: Xubo Luo
 * @Date: 2022-10-29 09:11:18
 * @Last Modified by: Xubo Luo
 * @Last Modified time: 2022-10-29 09:57:43
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#include <map>

using namespace std;

#define fr1 for (int i = 0; i < n; i++)
#define fr2 for (int j = 0; j < n; j++)
#define pii pair<int, int>
#define tii tuple<int, int, int>

const int N = 2e6 + 10;
// int n, k;
// int a[N], num[2 * N], cont[2*N];
int n, a, b;
string s;

void solve()
{
    cin >> n >> a >> b;

    if (a - 1 <= n - a)
    { // 上
        for (int i = 1; i < n; i++)
        {
            cout << "U";
        }
        for (int i = 1; i < a; i++)
        {
            cout << "D";
        }
    }
    else
    { // 下
        for (int i = 1; i < n; i++)
        {
            cout << "D";
        }
        for (int i = a; i < n; i++)
        {
            cout << "U";
        }
    }
    if (b - 1 <= n - b)
    {
        for (int i = 1; i < n; i++)
        {
            cout << "L";
        }
        for (int i = 1; i < b; i++)
        {
            cout << "R";
        }
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            cout << "R";
        }
        for (int i = b; i < n; i++)
        {
            cout << "L";
        }
    }
}

void solve2()
{
    cin >> n >> a >> b;
    string str = "";
    bool l = false;
    bool r = false;
    if (a <= n / 2)
    {
        l = true;
    }
    if (b <= n / 2)
    {
        r = true;
    }
    if (l && r)
    {
        for (int i = 0; i < n - 1; i++)
        {
            str += "L";
            str += "U";
        }
    }
    else if (!l && r)
    {
        for (int i = 0; i < n - 1; i++)
        {
            str += "L";
            str += "D";
        }
    }
    else if (l && !r)
    {
        for (int i = 0; i < n - 1; i++)
        {
            str += "R";
            str += "U";
        }
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            str += "R";
            str += "D";
        }
    }

    if (l && r)
    {
        for (int i = 1; i < a; i++)
        {
            str += "D";
        }
        for (int i = 1; i < b; i++)
        {
            str += "R";
        }
    }
    else if (!l && r)
    {
        for (int i = n; i > a; i--)
        {
            str += "D";
        }
        for (int i = 1; i < b; i++)
        {
            str += "R";
        }
    }
    else if (l && !r)
    {
        for (int i = 1; i < a; i++)
        {
            str += "D";
        }
        for (int i = n; i > b; i--)
        {
            str += "L";
        }
    }
    else
    {
        for (int i = n; i > b; i--)
        {
            str += "L";
        }
        for (int i = n; i > a; i--)
        {
            str += "D";
        }
    }
    cout << str;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}