#include <bits/stdc++.h>
using namespace std;
#define db double
int sz[200005];
vector <int> g[200005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> sz[i];
        for (int j = 1; j <= sz[i]; j++)
        {
            int p; cin >> p;
            g[p].push_back(i);
        }
    }
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        double res = 1;
        for (int x : g[i])
            res = min(res, (db)(sz[x] - 1)/sz[x]);
        ans = max(ans, res);
    }
    cout << fixed << setprecision(9) << ans;
}
