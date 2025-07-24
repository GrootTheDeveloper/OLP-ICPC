#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int divs[100005], a[100005], f[100005];
void sie(int lim)
{
    for (int i = 2; i <= lim; i++)
        if (!divs[i]) for (int j = i; j <= lim; j += i) divs[j] = i;
}
void proc(int n)
{
    while (n != 1)
    {
        int p = divs[n];
        int cnt = 0;
        while (n % p == 0) cnt++, n/=p;
        f[p] = max(f[p], cnt);
    }
}
int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = (res * a) % mode;
        a = a * a % mode;
        b >>= 1;
    }
    return res;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int lim = 0;
    for (int i = 1; i <= n; i++) cin >> a[i], lim = max(lim, a[i]);
    sie(lim);
    for (int i = 1; i <= n; i++) proc(a[i]);
    int res = 1;
    for (int i = 2; i <= lim; i++)
        if (f[i]) res = (res * power(i, f[i])) % mode;
    cout << res;

}
