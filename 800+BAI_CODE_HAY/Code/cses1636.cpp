#include <bits/stdc++.h>
using namespace std;
int xu[111],dp[(int)1e6+5];
const int mode = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x; cin >> n >> x;
    for (int i=1;i<=n;i++) cin >> xu[i];
    dp[0]=1;
    for (int j=1;j<=n;j++)
        for (int i=1; i<=x; i++)
            if (xu[j]<=i) dp[i]=(dp[i]+dp[i-xu[j]])%mode;
    return cout << dp[x]%mode,0;

}
