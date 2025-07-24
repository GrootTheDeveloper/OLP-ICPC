#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1005;

int seg[N * 4], a[1001][1001], dp[1001][1001], par[1001][1001];

void update(int id, int l, int r, int pos, int val)
{
    if (pos > r || pos < l) return;
    if (l == r && l == pos) return seg[id] = val, void();
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r)/2;
    return max(get(id *2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("frog.inp","r",stdin);
    freopen("frog.out","w",stdout);
    int m,n,k; cin >> m >> n >> k;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = a[1][i];
        update(1,1,n,i,a[1][i]);
    }
    for (int i = 2; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            dp[i][j] = get(1,1,n,max(1ll, j - k),min(n,j + k)) + a[i][j];
        for (int j = 1; j <= n; j++)
            update(1,1,n,j,dp[i][j]);
    }

    int pos = 0;
    for (int i = 1; i <= n; i++) if (dp[m][i] > dp[m][pos]) pos = i;
    cout << dp[m][pos] << '\n';
    int x = m;
    vector <int> vec;
    while (x)
    {
        vec.push_back(pos);
        for (int i = max(1ll, pos - k); i <= min(n, pos + k); i++)
           if (dp[x - 1][i] + a[x][pos] == dp[x][pos]) {pos = i; break;}
        x--;
    }
    reverse(begin(vec), end(vec));
    for (int val : vec) cout << val << '\n';
}
