#include <bits/stdc++.h>

using namespace std;

int main(){

    long long n;
    cin>>n;

    long long dp[1000][3];

    dp[1][1]=1;dp[1][2]=1;dp[1][3]=1;

    for(long long i=2;i<=n;i++){

       dp[i][1]=dp[i-1][1]+dp[i-1][2]+dp[i-1][3];
       dp[i][2]=dp[i-1][1]+dp[i-1][2]+dp[i-1][3];
       dp[i][3]=dp[i-1][1]+dp[i-1][2];
    }
    cout<<dp[n][1]+dp[n][2]+dp[n][3];
}
