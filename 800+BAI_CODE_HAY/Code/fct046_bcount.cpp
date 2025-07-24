#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

int pre[4][100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int ai; cin >> ai;
        for (int j = 1; j <= 3; j++)
            pre[j][i] = pre[j][i - 1] + (ai == j);
    }
    while (q--)
    {
        int l, r; cin >> l >> r;
        for (int i = 1; i <= 3; i++)
            cout << pre[i][r] - pre[i][l - 1] << ' ';
        cout << '\n';
    }
}
