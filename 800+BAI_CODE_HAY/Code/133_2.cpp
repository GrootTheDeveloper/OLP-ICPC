#include <bits/stdc++.h>
using namespace std;
#define int long long

struct DSU
{
    vector <int> second;
    vector <bool> us;
    DSU (int n)
    {
        second.resize(n + 4);
        us.assign(n + 4, false);
        for (int i = 1; i < n; i++) second[i] = i + 1;
        second[n] = 1;
    }
    int find(int v)
    {
        if (!us[v]) return v;
        return second[v] = find(second[v]);
    }
};

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    DSU d(n);
    for (int i = 1; i <= n; i++)
    {
        int ai; cin >> ai;
        int ans = d.find(ai);
        cout << ans << ' ';
        d.us[ans] = true;
    }

}
