/*
 * @Author: Xubo Luo
 * @Date: 2022-10-29 09:11:18
 * @Last Modified by: Xubo Luo
 * @Last Modified time: 2022-10-29 11:01:38
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
int n, k;
int a[N], num[4 * N], cont[4 * N];

string s;

void solve()
{
    cin >> n >> k;
    int maxn = 0;
    fr1
    {
        scanf("%d", &a[i]);
        num[a[i] + N]++;
        maxn = max(maxn, num[a[i] + N]);
    }
    if (k)
    {
        fr1
        {
            int x = a[i];
            cont[x + N]--;
            cont[x + N] = max(cont[x + N], 0);
            cont[x + N + k]++;
            maxn = max(maxn, cont[x + N + k] + num[x + N + k]);
        }
    }
    cout << maxn << '\n';
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