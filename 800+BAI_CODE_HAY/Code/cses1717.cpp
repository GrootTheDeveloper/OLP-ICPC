#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[1000006];
const int mode=1e9+7;
int main()
{
    int n; cin >> n;
    dp[2]=1;
    for (int i=3;i<=n;i++)
        dp[i]=(i-1)*(dp[i-1]+dp[i-2])%mode;
    return cout << dp[n]%mode,0;
}
