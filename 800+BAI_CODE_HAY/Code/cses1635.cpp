#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=1e6+5,mode=1e9+7;
int dp[MAX+1],xu[101];

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x; cin >> n >> x;
    for (int i=1;i<=n;i++) cin >> xu[i];
    sort(xu+1,xu+n+1);
    dp[0]=1;
    for (int i=xu[1]; i<=x; i++)
        for(int j=1; j<=n; j++)
        {
            if (xu[j]<=i) dp[i]+=dp[i-xu[j]]%mode;
            else break;
        }
    cout << dp[x]%mode;
    return 0;

}

