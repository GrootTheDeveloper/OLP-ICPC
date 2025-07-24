#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
vector <int> p;
bool prime[2003];
int dp[1005][1005];
void sie(int N)
{
    for (int i = 2; i <= N; i++)
        if (!prime[i])
        {
            p.push_back(i);
            for (int j = i*i; j <= N; j += i) prime[j] = true;
        }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,k; cin >> n >> k;
    sie(2 * k);
    for (int i = 0; i <= k; i++) dp[1][i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= k; j++)
            for (int z : p)
            {
                if (z < j) continue;
                if (z - j > k) break;
                dp[i][j] += dp[i - 1][z - j];
                dp[i][j] %= mode;
            }
    int res = 0;
    for (int i = 0; i <= k; i++)
        res = (res + dp[n][i]) % mode;
    cout << res;
}
