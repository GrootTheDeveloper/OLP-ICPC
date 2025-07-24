#include <bits/stdc++.h>
using namespace std;
#define int long long

struct DSU
{
    vector <int> par;
    int scc;
    DSU (int n)
    {
        par.resize(n + 1);
        scc = n;
        for (int i = 1; i <= n; i++) par[i] = i;
    }
    int find(int v)
    {
        return (v ==par[v]? v : par[v] = find(par[v]));
    }
    void Union(int a, int b)
    {
        a = find(a); b = find(b);
        if (a == b) return;
        scc--;
        if (a > b) swap(a,b);
        par[b] = a;
    }
};

int n, q;
void sub1()
{
    DSU d1(n), d2(n);
    while (q--)
    {
        int kind, u, v;
        cin >> kind >> u >> v;
        if (kind == 1) d1.Union(u,v);
        if (kind == 2) d2.Union(u,v);
        if (d1.scc != d2.scc)
        {
            cout << "No" << '\n';
            continue;
        }
        int ok = true;
        for (int i = 1; i <= n; i++)
        if (d1.find(i) != d2.find(i)) {ok = false; break;}
        cout << (ok? "Yes" : "No") << '\n';
    }
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    if (n <= 5000 && q <= 5000) sub1();
}
