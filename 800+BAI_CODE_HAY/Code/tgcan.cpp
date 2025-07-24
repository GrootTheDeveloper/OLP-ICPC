#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[100005],pre[1000005],mx;
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n; cin >> n;
    int ai;
    for (int i=1;i<=n;i++) cin >> ai,f[ai]++,mx=max(mx,ai);
    for (int i=1;i<=mx;i++) pre[i]=pre[i-1]+f[i];
    int res=0;
    for (int i=1;i<=mx;i++)
    if (f[i]>=2)
    {
    	res+=(f[i]*(f[i]-1)/2)*(pre[i-1]+(pre[min(i*2-1,mx)]-pre[i]));
    	res+=f[i]*(f[i]-1)*(f[i]-2)/6;
    }
    cout << res;
}
