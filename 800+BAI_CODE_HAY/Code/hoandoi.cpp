#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[200005], c[200005], b[200005];

void sub1()
{
    int ans = 1e15;
    for (int x = 1; x <= n; x++)
    {
        for (int i = 1; i < n; i++)
        {
            int cost = 0;
            for (int j = 1; j <= i; j++)
                if (a[j] > x) cost += c[j];
            for (int j = i + 1; j <= n; j++)
                if (a[j] <= x) cost += c[j];
            ans = min(ans, cost);
        }
    }
    cout << min({c[1], c[n], ans});
}


void sub2()
{
    int ans = 1e15;
    for (int i = 1; i <= n; i++)
        b[a[i]] = c[i];
    for (int i = 1; i <= n; i++) b[i] += b[i - 1];

    for (int x = 1; x <= n; x++)
    {
        int cost = b[x];
        for (int i = 1; i < n; i++)
        {
            if (a[i] <= x) cost -= c[i];
            if (a[i] > x) cost += c[i];
            ans = min(ans, cost);
        }
    }
    cout << min({ans, c[1], c[n]});
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    if (n <= 500) sub1();
    else if (n <= 5000) sub2();
//    sub1();
//    sub2();
}
