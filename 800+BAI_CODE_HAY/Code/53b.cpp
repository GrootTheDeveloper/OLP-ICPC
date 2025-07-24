#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[2000006],f[2000006],lim;
bool prime[2000006];
void sie()
{
    int N=trunc(sqrt(lim));
    for (int i=2;i<=N;i++)
    if (!prime[i]) for (int j=i*i;j<=lim;j+=i) prime[j]=true;
    for (int i=2;i<=lim;i++) if (!prime[i]) f[i]=i;else f[i]=f[i-1];
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("TWODIV.INP","r",stdin);
    freopen("TWODIV.OUT","w",stdout);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i],lim=max(lim,a[i]);
    sie();
    for (int i=1;i<=n;i++) cout << f[a[i]] << ' ';
}
