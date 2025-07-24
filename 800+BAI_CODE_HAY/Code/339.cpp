#include <bits/stdc++.h>
using namespace std;
#define int long long
bool pre[32005];
int p[32000];
int lim;
void sie()
{
    for (int i = 2; i <= 32000; i++)
        if (!pre[i])
        {
            p[++lim] = i;
            for (int j = i * i; j <= 32000; j += i) pre[j] = true;
        }
}
int calc(int n)
{
    int res = 1;
    for (int i = 1; i <= lim && n != 1; i++)
    {
        int cnt = 0;
        while (n % p[i] == 0) cnt++, n /= p[i];
        res *= (cnt + 1);
    }
    if (n != 1) res *= 2;
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    int q; cin >> q;
    sie();
    while (q--)
    {
        int x; cin >> x;
        cout << calc(x) << '\n';
    }
}
