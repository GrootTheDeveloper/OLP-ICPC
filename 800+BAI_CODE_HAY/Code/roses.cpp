#include <bits/stdc++.h>
using namespace std;

bool isSwap = false;
struct node
{
    int x1, y1, x2, y2;

    int friend operator + (const node &a, const node &b)
    {
        return (a.x2 - a.x1 + a.y2 - a.y1 + 2) * 2 + (b.x2 - b.x1 + b.y2 - b.y1 + 2) * 2;
    }
    bool friend operator < (const node &a, const node &b)
    {
        return (a.x2 - a.x1 + a.y2 - a.y1 + 2) * 2 < (b.x2 - b.x1 + b.y2 - b.y1 + 2) * 2;
    }
    void pr()
    {
        if (isSwap) swap(x1,y1), swap(x2, y2);
        cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2;
    }
} lef[360005], rig[360005], on[360005], down[360005];
int m, n, k;
vector<vector<signed>> a;
vector<vector<int>> c;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("roses.inp","r",stdin);
    freopen("roses.out","w",stdout);
    cin >> m >> n >> k;
    a.resize(m + 1, vector<signed> (n + 1, 0));
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
    {
        char ai; cin >> ai;
        if (ai == '#') a[i][j] = 1;
        else a[i][j] = 0;
    }
    if (m > n) isSwap = true, swap(m, n);
    c.resize(n + 1, vector<int> (m + 1, 0));
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
    {
        if (isSwap) c[j][i] = c[j][i - 1] + a[j][i];
        else c[j][i] = c[j][i - 1] + a[i][j];
    }

    for (int i = 0; i <= m + 1; i++)
        on[i] = {0, 0, (int)1e6, (int)1e6}, down[i] = on[i];
    for (int i = 0; i <= n + 1; i++)
        lef[i] = {0, 0, (int)1e6, (int)1e6}, rig[i] = lef[i];

    for (int x = 1; x <= m; x++)
    for (int y = x; y <= m; y++)
    {
        int l = 1, sum = 0;
        for (int r = 1; r <= n; r++)
        {
            sum += c[r][y] - c[r][x - 1];
            while (sum >= k)
            {
                if (sum == k)
                {
                    node tmp = {x, l, y, r};
                    if (tmp < on[y]) on[y] = tmp;
                    if (tmp < lef[r]) lef[r] = tmp;
                    if (tmp < rig[l]) rig[l] = tmp;
                    if (tmp < down[x]) down[x] = tmp;
                }
                sum -= c[l][y] - c[l][x - 1];
                l++;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    if (lef[i - 1] < lef[i]) lef[i] = lef[i - 1];

    for (int i = n - 1; i >= 1; i--)
    if (rig[i + 1] < rig[i]) rig[i] = rig[i + 1];

    for (int i = 2; i <= m; i++)
    if (on[i - 1] < on[i]) on[i] = on[i - 1];

    for (int i = m - 1; i >= 1; i--)
    if (down[i + 1] < down[i]) down[i] = down[i + 1];

    node ans1 = {0, 0, (int)1e6, (int)1e6}, ans2 = {0, 0, (int)1e6, (int)1e6};
    for (int i = 1; i <= n - 1; i++)
        if (lef[i] + rig[i + 1] < ans1 + ans2) ans1 = lef[i], ans2 = rig[i + 1];
    for (int i = 1; i <= m - 1; i++)
        if (on[i] + down[i + 1] < ans1 + ans2) ans1 = on[i], ans2 = down[i + 1];

    if (ans1.x2 == 1e6 || ans2.x2 == 1e6) return cout << -1, 0;
    cout << ans1 + ans2 << '\n';
    ans1.pr();
    cout << '\n';
    ans2.pr();

}
