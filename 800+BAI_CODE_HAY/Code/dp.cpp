#include <bits/stdc++.h>

using namespace std;
  long long a[1000000];
    long long dp[1000000];

int main(){

    long long n,s;

    cin>>n>>s;
    for(long long i=1;i<=s;i++)
        dp[i]=1e7;

    dp[0]=0;

    for(long long i=1;i<=n;i++)
     cin>>a[i];

    for(long long i=1;i<=n;i++)
     for(long long j=a[i];j<=s;j++)

       dp[j]= min( dp[j], dp[j- a[i]]+1);

    cout<< dp[s];
}
