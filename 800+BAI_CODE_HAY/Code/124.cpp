#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<double,double>
#define fi first
#define se second
const double ch = 0.0000001;
ii ver[1005];
int n;
double calc(ii a, ii b)
{
    return sqrt((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}

bool check(double x)
{
    x = x * 2;
    vector <bool> vs(n + 1, false);
    queue <ii> q;
    q.push(ver[1]);
    vs[1] = true;
    while (q.size())
    {
        ii top = q.front(); q.pop();
        for (int i = 1; i <= n; i++) if (vs[i] == false)
        {
            if (calc(ver[i], top) <= x)
            {
                vs[i] = true;
                q.push(ver[i]);
            }
        }
    }
    for (int i = 1; i <= n; i++) if (vs[i] == false) return false;
    return true;
}

void solve()
{
    double l = 1, r = 1e9 + 4;
    for (int i = 1; i <= 60; i++)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(6) << l;
}


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> ver[i].fi >> ver[i].se;
    solve();

}
