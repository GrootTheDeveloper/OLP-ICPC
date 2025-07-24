#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
#define val first
#define id second
ii a[100005], b[100005];

int calc(pair<int,int> a, pair<int,int> b)
{
    return  (a.first - b.first) * (a.first - b.first) + (a.second - b.second) *  (a.second - b.second);
}
bool us[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x1, x2, y1, y2; cin >> n >> x1 >> y1 >> x2 >> y2;
    priority_queue <ii> q;
    for (int i = 1; i <= n; i++)
    {
        int x,y; cin >> x >> y;
        a[i].val = calc({x,y},{x1,y1});
        b[i].val = calc({x,y},{x2,y2});
        a[i].id = b[i].id = i;
        q.push(b[i]);
    }
    sort(a + 1, a + n + 1);
    int res = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        int r1 = a[i].val;
        //us[a[i].id] = true;
        int r2 = 0;
        for (int j = i + 1; j <= n; j++)
            r2 = max(r2, b[a[j].id].val);
        res = min(res, r1 + r2);
    }
    cout << res;
}
