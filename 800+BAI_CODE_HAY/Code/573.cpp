#include <bits/stdc++.h>
using namespace std;
#define int long long
string s, rot = "#marisa";
const int mode = 1e9 + 7;
int dp[10];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    dp[0] = 1;
    for (int c : s)
    {
        for (int i = 1; i <= 6; i++)
            if (c == rot[i])
            {
                dp[i] += dp[i - 1];
                dp[i] %= mode;
            }
    }
    cout << dp[6];

}
