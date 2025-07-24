#include <bits/stdc++.h>
using namespace std;
#define int long long
int m, n, q;
int a[505][505], x[555], y[555], d[555], col[555], row[555];

int calc()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                for (int z = 1; z <= n; z++)
                {
                    ans = max(ans, col[i] + col[j] + row[z] - a[z][i] - a[z][j]);
                    ans = max(ans, row[i] + row[j] + col[z] - a[i][z] - a[j][z]);
                }
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                for (int z = j + 1; z <= n; z++)
                {
                    ans = max(ans, col[i] + col[j] + col[z]);
                    ans = max(ans, row[i] + row[j] + row[z]);
                }
        return ans;
}

void sub1()
{
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= m; i++)
    {
        cin >> x[i] >> y[i] >> d[i];
        a[x[i]][y[i]] = d[i];
        row[x[i]] += d[i];
        col[y[i]] += d[i];
    }
    cout << calc() << '\n';
    while (q--)
    {
        int t, w; cin >> t >> w;

        a[x[t]][y[t]] += w;
        row[x[t]] += w;
        col[y[t]] += w;

        int ans = calc();
        a[x[t]][y[t]] = d[t];
        row[x[t]] -= w;
        col[y[t]] -= w;
        cout << ans << '\n';
    }


}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("THREE.INP","r",stdin);
    freopen("THREE.OUT","w",stdout);
    int t; cin >> t;
    while (t--)
    {
        cin >> n >> m >> q;
        sub1();
    }

}
