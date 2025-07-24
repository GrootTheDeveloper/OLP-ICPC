#include <bits/stdc++.h>
using namespace std;

struct node
{
    int cnt[10];
    int cur;
    bool isDigit = false;
};
node orz(node &a, node &b)
{
    if (a.cur > b.cur) return a;
    if (b.cur > a.cur) return b;
    int pos = 9;
    while (a.cnt[pos] == b.cnt[pos] && pos >= 0) pos--;
    if (pos == -1) return a;
    if (a.cnt[pos] > b.cnt[pos]) return a;
    return b;

}
node dp[100005];
int d[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int a[10];
bool mark[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    mark[0] = true;
    for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--)
    {
        if (i - d[a[j]] >= 0)
        {
            if (mark[i - d[a[j]]])
            {
                if (a[j] != 0 || (a[j] == 0 && dp[i - d[a[j]]].isDigit))
                {
                    node tmp = dp[i - d[a[j]]];
                    tmp.cur++;
                    tmp.cnt[a[j]]++;
                    dp[i] = orz(dp[i], tmp);
                    dp[i].isDigit = true;
                    mark[i] = true;
                }
            }
        }
    }
    for (int i = 9; i >= 0; i--)
    for (int j = 1; j <= dp[n].cnt[i]; j++)
        cout << i;
    if (mark[n] == false) cout << 0;

}
