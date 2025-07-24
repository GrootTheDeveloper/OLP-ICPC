#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=1e6+5,mode=1e9+7;
int dp[MAX+1],xs[7]={0,1,2,3,4,5,6};

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x; cin >> x;
    dp[0]=1;
    for (int i=xs[1]; i<=x; i++)
        for(int j=1; j<=6; j++)
        {
            if (xs[j]<=i) dp[i]+=dp[i-xs[j]]%mode;
            else break;
        }
    cout << dp[x]%mode;
    return 0;

}


