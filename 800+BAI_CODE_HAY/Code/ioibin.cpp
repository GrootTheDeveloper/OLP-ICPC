#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e4 + 5;
int par[maxn], p, n;

void make_set()
{
    for (int i = 0; i <= n; i++) par[i] = i;
}
int find(int v)
{
    if (v == par[v]) return v;
    return par[v] = find(par[v]);
}
void Union(int a, int b)
{
    a = find(a); b = find(b);
    if (a == b) return;
    //if (sz[a] < sz[b]) swap(a,b);
    par[b] = a;
    //sz[a] += sz[b];
}


void solve()
{
    cin >> p;
    n = 20000;
    make_set();
    while (p--)
    {
        int x,y,kind; cin >> x >> y >> kind;
        if (kind == 1) Union(x,y);
        else
        {
            x = find(x); y = find(y);
            cout << ((x == y)? 1 : 0) << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
}


