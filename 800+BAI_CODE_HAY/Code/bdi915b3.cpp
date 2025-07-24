#include <bits/stdc++.h>
using namespace std;
int a[101][101], dp[101][101];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++) dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + a[i][j];
    int pos = 0;
    for (int i =1; i <= n; i++) if (dp[n][i] > dp[n][pos]) pos = i;
    vector <int> vec;
    int x = n, y = pos;
    while (x > 0)
    {
        vec.push_back(a[x][y]);
        if (dp[x - 1][y] + a[x][y] == dp[x][y]) x--;
        else x--,y--;
    }
    cout << dp[n][pos] << '\n';
    reverse(vec.begin(), end(vec));
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i != vec.size() - 1) cout << ' ';
    }
}
