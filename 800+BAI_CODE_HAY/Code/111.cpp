#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define wi first
#define vi second


const int maxn = 1e6 + 5e4;
int a[50], len1, len2, l[maxn], w[50], v[50], mid, val[maxn], n, s;
bool mark[50];
ii v1[maxn], v2[maxn];


void check(int lim)
{
    int bg = ((lim == mid)? 1 : mid + 1);
    int wi = 0, vi = 0;
    for (int i = bg; i <= lim; i++) wi += mark[i] * w[i], vi += mark[i] * v[i];
    if (wi > s) return;
    if (lim == mid) v1[++len1] = {wi, vi};
    else v2[++len2] = {wi,vi};
}

void Try(int i, int lim)
{
    if (i > lim) return check(lim), void();
    mark[i] = 1;
    Try(i + 1, lim);
    mark[i] = 0;
    Try(i + 1, lim);
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
    mid = n / 2;
    Try(1, mid);
    Try(mid + 1, n);
    sort(v2 + 1, v2 + len2 + 1);
    for (int i = 1; i <= len2; i++) l[i] = max(l[i - 1], v2[i].vi), val[i] = v2[i].wi;
    int res = 0;
    for (int i = 1; i <= len1; i++)
    {
        int pos = upper_bound(val + 1, val + len2 + 1, s - v1[i].wi) - val - 1;
        res = max(res, v1[i].vi + l[pos]);
    }
    cout << res;


}
