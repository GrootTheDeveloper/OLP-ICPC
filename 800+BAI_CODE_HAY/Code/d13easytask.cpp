#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e6+2;
bool prime[M];
int f[M];
void sieve()
{
    prime[1]=true;
    for (int i=2; i*i<=M;i+=1)
    {
        if (!prime[i])
            for (int j=i*i;j<=M;j+=i) prime[j]=true;
    }
    return;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,ai,MIN=INT_MAX,res=INT_MIN; cin >> n;
    sieve();
    for (int i=1;i<=n;i++)
    {
        cin >> ai;
        f[i]=f[i-1]+ai;
        if (!prime[i])
        {
            MIN=min(MIN,f[i-1]);
            res=max(res,f[i]-MIN);
        }
    }
    cout << res;
}
