#include <bits/stdc++.h>
using namespace std;

int d[1500][1500];
bool us[1500][1500];
bitset<1300> B[1300][60];
vector<int> g[1300];
bool red[250005];
int x[505], y[505];
int n, k;
void bfs(int s)
{
    queue<int> q;
    us[s][s] = true;
    q.push(s);
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (!us[s][v])
        {
            us[s][v] = true;
            d[s][v] = d[s][u] + 1;
            q.push(v);
        }
    }
    for (int i = 1; i <= n * (n + 1)/2; i++)
    if (!red[i]) B[s][d[s][i]].set(i);

}
void sub1()
{

    for (int i = 1; i <= n; i++)
    {
        x[i] = y[i - 1] + 1;
        y[i] = i * (i + 1) / 2;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = x[i]; j <= y[i]; j++)
        {
            g[j].push_back(j + i);
            g[j + i].push_back(j);
            g[j + i + 1].push_back(j);
            g[j].push_back(j + i + 1);
            if (j + 1 <= y[i]) g[j].push_back(j + 1), g[j + 1].push_back(j);

        }
    }
    for (int i = x[n]; i < y[n]; i++)
        g[i].push_back(i + 1), g[i + 1].push_back(i);

    for (int i = 1; i <= n * (n + 1) / 2; i++)
        bfs(i);

    long long ans = 0;
    int all = n * (n + 1) / 2;
    for (int i = 1; i <= all; i++)
    for (int j = i + 1; j <= all; j++)
        if (!red[i] && !red[j])
        {
            int dic = d[i][j];
            ans += (B[i][dic] & B[j][dic]).count();
        }
    cout << ans / 3;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int ai; cin >> ai;
        red[ai] = true;
    }
    if (n <= 50) sub1();

}
