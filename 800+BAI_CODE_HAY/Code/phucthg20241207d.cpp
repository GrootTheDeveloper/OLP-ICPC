#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
vector<ii> lis[5000];
bool mark[2002][2002];
char a[2002][2002];
int m, n;

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    lis[1].push_back({1, 1});
    for (int i = 1; i <= m + n - 1; i++)
    {
        char c = 'z';
        for (ii tmp : lis[i])
            if (a[tmp.fi][tmp.se] < c) c = a[tmp.fi][tmp.se];
        cout << c;
        for (ii tmp : lis[i])
        {
            int x = tmp.fi, y = tmp.se;
            if (a[x][y] == c)
            {
                if (x + 1 <= m && !mark[x + 1][y])
                    lis[i + 1].push_back({x + 1, y}), mark[x + 1][y] = true;
                if (y + 1 <= n && ! mark[x][y + 1])
                    lis[i + 1].push_back({x, y + 1}), mark[x][y + 1] = true;
            }
        }
    }
}
