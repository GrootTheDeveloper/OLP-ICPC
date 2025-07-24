#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define iii pair<int, ii>
#define fi first
#define se second
double x[3003], y[3003];
int n;
iii eg[9000000];
bitset<3003> g[3003];
double dic(int &i, int &j)
{
    double a = x[i] - x[j], b = y[i] - y[j];
    return sqrt(a * a + b * b);
}

void sub1()
{
    double ans = 0.0;
    for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
    for (int z = j + 1; z <= n; z++)
        ans = max(ans, min({dic(i, j) / 2, dic(i, z) / 2, dic(j, z) / 2}));
    cout << fixed << setprecision(14) << ans;
}
int p2(int x) {return x * x;}
void sub2()
{
    int lim = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            eg[++lim] = {p2(x[i] - x[j]) + p2(y[i] - y[j]), {i, j}};
    sort(eg + 1, eg + lim + 1);
    for (int i = lim; i >= 1; i--)
    {
        int x = eg[i].se.fi, y = eg[i].se.se;
        if ((g[x] & g[y]).count() != 0)
        {
            cout << fixed << setprecision(14) << sqrt(eg[i].fi)/2;
            return;
        }
        g[x].set(y);
        g[y].set(x);
    }
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    if (n <= 500) sub1();
    else sub2();
}
