#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int n;
int a[N];

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        scanf("%d", &n);

        ll res = 0;
        bool stp = true, stn = true;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] < 0)
                stp = false;
            else if (a[i] > 0)
                stn = false;
        }

        if (n == 1)
        {
            cout << a[0] << '\n';
            continue;
        }

        int resmin = 1e9 + 10;
        for (int i = 0; i < n; i++)
            resmin = min(resmin, abs(a[i]));

        if (!stp && !stn)
        {
            for (int i = 0; i < n; i++)
                res += abs(a[i]);
        }
        else
        {
            for (int i = 0; i < n; i++)
                res += abs(a[i]);

            res -= 2 * resmin;
            // bool st = false;
            // for (int i = 0; i < n; i++)
            //     if (abs(a[i]) == resmin && !st)
            //         st = true;
            //     else
            //         res += abs(a[i]);

            // res -= resmin;
        }

        printf("%lld\n", res);
    }

    return 0;
}