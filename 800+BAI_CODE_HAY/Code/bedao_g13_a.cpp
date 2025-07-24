#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[555];
main()
{
    int n; cin >> n;
    if (n==2) return cout << 1,main();
    dp[0]=1;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=i;j++)
    {
        dp[i]+=dp[i-j];
    }
    cout << dp[n];
}
