#include <bits/stdc++.h>
using namespace std;
#define int long long

unordered_map <int,int> par, idx;
vector <pair<int,int>> g[100005];
vector <int> lis[100005];
pair <int,int> Case[100005];


int find(int v)
{
    if (par[v] == v) return v;
    return par[v] = find(par[v]);
}
void Union(int a, int b)
{
    a = find(a); b = find(b);
    if (a == b) return;
    par[b] = a;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m; cin >> n >> m;
    vector <int> vec;
    for (int i = 1; i <= m; i++)
    {
        int x,y; cin >> x >> y;
        if (par[x] == 0) vec.push_back(x), par[x] = x;
        if (par[y] == 0) vec.push_back(y), par[y] = y;
        Union(x,y);
    }
    int scc = 0;
    for (int val : vec)
    {
        int u = find(val);
        if (idx[u] == 0) idx[u] = ++scc;
        lis[idx[u]].push_back(val);
    }
    for (int i = 1; i <= scc; i++)
        sort(lis[i].begin(),lis[i].end());
    sort(lis + 1, lis + scc + 1);

    cout << scc << '\n';
    for (int i = 1; i <= scc; i++)
    {
        cout << lis[i].size() << '\n';
        for (int x : lis[i]) cout << x << ' ';
        cout << '\n';
    }

}
