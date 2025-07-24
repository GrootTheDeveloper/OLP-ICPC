#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7, base = 311;

int p[200005], Hash[51][200005];
int n, k;
string s[55];
int gethash(int id, int l, int r)
{
    return (Hash[id][r] - Hash[id][l - 1] * p[r - l + 1]);
}


int ok(int l)
{
    map<int,int> f;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j + l - 1 < s[i].size(); j++)
            f[gethash(i, j, j + l - 1)] |= (1 << i);
    }
    for (auto x : f)
        if (__builtin_popcountll(x.second) >= k) return x.first;
    return -1e18;

}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("thuyvan.inp","r",stdin);
    freopen("thuyvan.out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> s[i], s[i] = " " + s[i];

    p[0] = 1;
    for (int i = 1; i <= 2e5; i++) p[i] = p[i - 1] * base;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s[i].size() - 1; j++)
            Hash[i][j] = (Hash[i][j - 1] * base + s[i][j]);
    }

    int l = 1, r = 2e5;
    int ans, len;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        int t = ok(mid);
        if (t != -1e18) ans = t, len = mid, l = mid + 1;
        else r = mid - 1;
    }

    for (int i = 1 ; i <= n; i++)
    {
        for (int j = 1; j + len - 1 <= s[i].size() - 1; j++)
            if (gethash(i, j, j + len - 1) == ans)
            {
                for (int id = j; id <= j + len - 1; id++) cout << s[i][id];
                return 0;
            }
    }
}
