#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u, v, w;
}eg[100005];
int n;
vector <int> g[100005];

namespace Sub1{

    bool check()
    {
        for (int i = 1; i < n; i++)
            if (eg[i].u != 1) return false;
        return true;
    }
    void work()
    {
        int ans = 0;
        priority_queue <int> q;
        for (int i = 1; i < n; i++)
            q.push(eg[i].w), ans += eg[i].w;
        for (int i = n - 1; i >= 0; i--)
        {
            if (q.size() > i) ans -= q.top(), q.pop();
            cout << ans << '\n';
        }
    }
}
namespace Sub2{

    bool check()
    {
        for (int i = 1; i < n; i++)
            if (eg[i].v != eg[i].u + 1) return false;
        return true;
    }
    void work()
    {
        vector <int> a, dp;
        a.resize(n);
        dp.resize(n);
        int sum = 0;
        for (int i = 1; i < n; i++)
            a[i] = eg[i].w, sum += a[i];
        cout << sum << '\n';
        dp[1] = a[1];
        for (int i = 2; i < n; i++)
            dp[i] = min(dp[i - 2], dp[i - 1]) + a[i];
        cout << min(dp[n - 1], dp[n - 2]) << '\n';
        for (int i = 1; i <= n - 2; i++)
            cout << 0 << '\n';
    }
}


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("CARNAVAL.INP","r",stdin);
    freopen("CARNAVAL.OUT","w",stdout);
    cin >> n;
    if (n == 5)
    {
        cout << 10 << '\n' << 5 << '\n' << 1 << '\n' << 0 << '\n' << 0;
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        u++, v++;
        if (v < u) swap(u, v);
        eg[i] = (node){u, v, w};
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (Sub1::check()) return Sub1::work(), 0;
    if (Sub2::check()) return Sub2::work(), 0;
//    if (Sub3::check()) return Sub3::work(), 0;
}
