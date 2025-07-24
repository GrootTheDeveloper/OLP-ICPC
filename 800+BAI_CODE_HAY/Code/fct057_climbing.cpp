#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define fi first
#define se second

priority_queue <ii> qmax;
priority_queue <ii, vector<ii>, greater<ii>> qmin;

int getmin(int pos)
{
    while (qmin.top().se < pos) qmin.pop();
    return qmin.top().fi;
}
int getmax(int pos)
{
    while (qmax.top().se < pos) qmax.pop();
    return qmax.top().fi;
}
int a[1000006];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, c; cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector <int> ans;
    for (int i = 1; i <= n; i++)
    {
        qmax.push({a[i], i});
        qmin.push({a[i], i});
        if (i < m) continue;
        if (getmax(i - m + 1) - getmin(i - m + 1) <= c) ans.push_back(i - m + 1);
    }
    for (int x : ans) cout << x << '\n';
    if (ans.size() == 0) cout << "NONE";
}
