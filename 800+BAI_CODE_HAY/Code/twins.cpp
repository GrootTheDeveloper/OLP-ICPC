#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int f[N+3],cnt[N+3];
bool prime[N+3];
int dn(int n)
{
    int res=0,temp=n;
    while (n) res=res*10+n%10,n/=10;
    if (res==temp) return 4;
    else return res;
}
void sie()
{
    int lim=trunc(sqrt(N));
    for (int i=2;i<=lim;i++)
        if (!prime[i]) for (int j=i*i;j<=N;j+=i) prime[j]=true;
    for (int i=2;i<=N;i++)
    {
        if (!prime[i])
        {
            f[i]=f[i-1]+i;
            cnt[i]=cnt[i-1]+(!prime[dn(i)]);
        }
        else
        {
            f[i]=f[i-1];
            cnt[i]=cnt[i-1];
        }
    }
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    sie();
    int a,b;
    while(t--)
    {
        cin >> a >> b;
        cout << f[b]-f[a-1] << ' ' << cnt[b]-cnt[a-1] << '\n';
    }

}
