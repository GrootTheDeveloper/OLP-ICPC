#include <bits/stdc++.h>
using namespace std;
#define int long long
int tol[555][555];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int m,n, k; cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
    {
        char ai; cin >> ai;
        tol[j][i] = tol[j][i - 1] + (ai - '0');
    }
    int res = 0;
    for (int x = 1; x <= m; x++)
        for (int y = x; y <= m; y++)
        {
            int l = 1, sum = 0;
            for (int i = 1; i <= n; i++)
            {
                sum += tol[i][y] - tol[i][x - 1];
                while (sum > k) sum -= (tol[l][y] - tol[l][x - 1]), l++;
                res = max(res, (y - x + 1) * (i - l + 1));
            }
        }
    cout << res;
}
