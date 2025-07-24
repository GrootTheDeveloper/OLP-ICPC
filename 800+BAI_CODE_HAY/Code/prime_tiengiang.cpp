#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[1000006];


void sie()
{
    for (int i=2;i<=1e6;i++) if (f[i]==0)
    for (int j=i;j<=1e6;j+=i) f[j]++;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("PRIME.INP","r",stdin);
    freopen("PRIME.OUT","w",stdout);
    int n; cin >> n;
    sie();
    int x,res=0,ans;
    for (int i=1;i<=n;i++)
    {
        cin >> x;
        if (f[x]>res) res=f[x],ans=x;
    }
    cout << ans;

}
