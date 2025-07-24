#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int n,q;
int a[100005];

void sub1()
{
    vector <vector<int>> dp(n + 1, vector<int> (n + 1, 0));
    for (int i = 1; i <= n; i++) dp[i][1] = 1;
    for (int i = 2; i <= n; i++)
        for (int k = 2; k <= i; k++)
            for (int j = i - 1; j >= 1; j--)
                if (a[j] * q == a[i]) dp[i][k] = (dp[i][k] + dp[j][k - 1]) % mode;
    for (int i = 2; i <= n; i++)
    {
        int res = 0;
        for (int j = i; j <= n; j++) res = (res + dp[j][i]) % mode;
        cout << res << ' ';
    }

}
void sub2()
{
    vector <vector<int>> dp(n + 1, vector<int> (31, 0));
    for (int i = 1; i <= n; i++) dp[i][1] = 1;
    for (int i = 2; i <= n; i++)
        for (int k = 2; k <= min(30ll, i); k++)
            for (int j = i - 1; j >= 1; j--)
            if (a[j] * q == a[i]) dp[i][k] = (dp[i][k] + dp[j][k - 1]) % mode;
    for (int i = 2; i <= n; i++)
    {
        if (i > 30) {cout << 0 << ' '; continue;}
        int res = 0;
        for (int j = i; j <= n; j++) res = (res + dp[j][i]) % mode;
        cout << res << ' ';
    }

}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sub1();
    cout << '\n';
    sub2();
}
