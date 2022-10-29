/*
 * @Author: Xubo Luo
 * @Date: 2022-10-29 09:11:18
 * @Last Modified by: Xubo Luo
 * @Last Modified time: 2022-10-29 12:00:18
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

const int N = 1e5 + 10;
int n, k;
int a, b;
string s;
bool st[N];
vector<int> vec;
map<pii, int> vis;

struct node
{
    int a, b, steps = 0;
};

void get_primes(int a)
{
    cout << "ssss\n";
    memset(st, true, sizeof st);
    for (int i = 2; i <= a; i++)
    {
        if (st[i] == true)
        {
            vec.push_back(i);
            for (int j = i; i <= a / j; j++)
            {
                st[i * j] = false;
            }
        }
    }
    cout << "done!\n";
}

int max_factor(int a, int b)
{

    for (int i = vec.size() - 1; i >= 0; i--)
    {
        if (a % vec[i] == 0 && b % vec[i] == 0)
        {
            return vec[i];
        }
    }
    return 1;
}

int bfs(queue<node> q)
{
    while (!q.empty())
    {
        node tmp = q.front();
        if (tmp.a == 1 || tmp.b == 1)
        {
            return tmp.steps;
        }
        q.pop();
        node ptmp, mtmp, dtmp;
        ptmp = {a + 1, b + 1, tmp.steps + 1};
        mtmp = {a - 1, b - 1, tmp.steps + 1};

        int fac = max_factor(tmp.a, tmp.b);
        cout << "-----" << fac << '\n';
        if (fac != 1)
        {
            dtmp = {a / fac, b / fac, tmp.steps + 1};
            if (vis[{dtmp.a, dtmp.b}] == 0)
            {
                q.push(dtmp);
                vis[{dtmp.a, dtmp.b}] = 1;
                cout << "*****" << dtmp.steps << '\n';
            }
        }
        // cout << ptmp.a << ' ' << ptmp.b << endl;
        // cout << mtmp.a << ' ' << mtmp.b << endl;
        if (vis[{ptmp.a, ptmp.b}] == 0)
        {
            q.push(ptmp);
            vis[{ptmp.a, ptmp.b}] = 1;
            cout << "*****" << ptmp.steps << '\n';
        }

        if (vis[{mtmp.a, mtmp.b}] == 0)
        {
            q.push(mtmp);
            vis[{mtmp.a, mtmp.b}] = 1;
            cout << "*****" << mtmp.steps << '\n';
        }
    }
}

void solve()
{
    vis.clear();
    scanf("%d %d", &a, &b);
    if (a > b)
        swap(a, b);
    queue<node> q;
    vis[{a, b}] = 1;
    node src = {a, b, 0};
    q.push(src);
    cout << bfs(q) << '\n';
}

int main()
{

    int t = 1;
    // cin >> t;
    int ttt = 1e9 + 10;
    get_primes(N);
    cout << max_factor(4, 8);
    while (t--)
    {
        // solve();
    }
    return 0;
}