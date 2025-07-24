#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;

int par[maxn], sz[maxn];

void make_set()
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = i;
        sz[i]  = 1;
    }
}
int find(int v)
{
    if (v == par[v]) return v;
    return par[v] = find(par[v]);
}
bool Union(int a, int b)
{
    a = find(a); b = find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a,b);
    par[b] = a;
    sz[a] += sz[b];
    return true;
}
void inp()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    inp();
    solve();
}


