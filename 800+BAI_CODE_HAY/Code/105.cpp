#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt[1000006], p[1000006];

void init()
{
    for (int i = 2; i <= 1e6; i++)
        if (!p[i]) for (int j = i; j <= 1e6; j+=i) p[j] = i;
}
int mask(int n)
{
    int res = 1;
    while (n != 1)
    {
        int k = p[n], x = 0;
        while (n % k == 0) x++, n /= k;
        if (x & 1) res *= k;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    init();
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int ai; cin >> ai;
        int x = mask(ai);
        res += cnt[x];
        cnt[x]++;
    }
    cout << res;
}
