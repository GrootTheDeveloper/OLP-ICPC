#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[101], b[101], c[101];

struct node
{
    double ans;
    vector<int> lis;
};

node orz(node a, node b)
{
    if (a.ans > b.ans) return a;
    return b;
}
node dp[101][101][101];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    for (int z = 1; z <= n; z++)
    if (a[i] == b[j] && b[j] == c[z]){
        node tmp = dp[i - 1][j - 1][z - 1];
        if (tmp.ans == 0) tmp.ans = log(a[i]);
        else tmp.ans += log(a[i]);
        tmp.lis.push_back(a[i]);
        dp[i][j][z] = tmp;
    } 
    else 
        dp[i][j][z] = orz(orz(dp[i - 1][j][z], dp[i][j - 1][z]), dp[i][j][z - 1]);
    
    cout << dp[n][n][n].lis.size() << '\n';
    for (int c : dp[n][n][n].lis)
        cout << c << ' ';
}
