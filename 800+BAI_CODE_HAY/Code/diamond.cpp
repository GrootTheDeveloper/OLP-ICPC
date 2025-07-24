#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

ii a[500005];
bool cmp(ii a, ii b)
{
    return (a.fi - a.se == b.fi - b.se? a.fi < b.fi : a.fi - a.se > b.fi - b.se);
}

bool mark[22];
int x = 1, y = 1000000;
int n,k;
void check()
{
    int sa = 0, sb = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
        if (mark[i]) sa += a[i].fi, sb += a[i].se, cnt++;
    if (sb == 0 || cnt != k) return;
    if ((double)sa/sb > (double)x/y) x = sa, y = sb;
}

void Try(int i)
{
    if (i > n) return check(), void();
    for (int x = 0; x <= 1; x++) 
    {
        mark[i] = x;
        Try(i + 1);
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi >> a[i].se;
    sort(a + 1, a + n + 1, cmp);
    int s = 0, t = 0;
    for (int i = 1; i <= k; i++)
    {
        s += a[i].fi;
        t += a[i].se;
    }
    cout << '\n';
    int gcd = __gcd(s,t);
    cout << s/gcd << ' ' << t/gcd;
    /*Try(1);
    gcd = __gcd(x,y);
    cout << x / gcd << ' ' << y / gcd;
    cout << '\n' << '\n';
    for (int i = 1; i <= k; i++) cout << a[i].fi << ' ' << a[i].se << '\n';*/
}
