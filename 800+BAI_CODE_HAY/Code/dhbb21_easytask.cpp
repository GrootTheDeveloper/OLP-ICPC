#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000007],f[1000007],n;
bool prime[1000006];
void se()
{
    prime[1]=true;
    for (int i=2;i<=n;i++)
        if (!prime[i])
        for (int j=i*i;j<=n;j+=i) prime[j]=true;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    se();
    int MIN=1e9,MAX=-1e18;
    for (int i=1;i<=n;i++)
    {
        f[i]=f[i-1]+a[i];
        if (!prime[i])
        {
            MIN=min(MIN,f[i-1]);
            MAX=max(MAX,f[i]-MIN);
        }

    }
    cout << MAX;
}
