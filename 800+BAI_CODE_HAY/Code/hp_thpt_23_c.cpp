#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1005],f[1005],m,x,y;
bool prime[10000007];

void sie()
{
    prime[0]=1;
    prime[1]=1;
    int N=trunc(sqrt(1e7));
    for (int i=2;i<=N;i++)
    if (!prime[i]) for (int j=i*i;j<=1e7;j+=i) prime[j]=true;
}
bool nt(int n)
{
    if (n<2) return 0;
    return (prime[n]==0);
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i], f[i]=f[i-1]+a[i];;
    sie();
    while (m--)
    {
        cin >> x >> y;
        cout << nt(f[y]-f[x-1]) << '\n';
    }
}
