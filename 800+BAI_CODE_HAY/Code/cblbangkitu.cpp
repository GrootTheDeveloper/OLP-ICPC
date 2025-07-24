#include <bits/stdc++.h>
using namespace std;
#define int long long

char a[456][456], col[456][456];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m, k; cin >> m >> n >> k;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            col[j][i] = col[j][i - 1] + (a[i][j] == 'a');
        }
    int ans = 0;
    for (int i = 1; i <= m; i++)
        for (int j = i + 1; j <= m; j++)
        {
            int sum = 0;
            queue <int> d[26];
            for (int x = 1; x <= n; x++)
            {
                sum += col[x][j] - col[x][i - 1];
                if (a[i][x] == a[j][x])
                {
                    int c = a[i][x] - 'a';
                    while(d[c].size())
                    {
                        if (sum - d[c].front() > k) d[c].pop();
                        else break;
                    }
                    ans += d[c].size();
                    d[c].push(sum - (col[x][j] - col[x][i - 1]));
                }
            }
        }
    cout << ans;

}
