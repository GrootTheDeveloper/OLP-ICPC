#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=1e9; 
int a[200005],f[200005];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i],a[i]=(a[i]+n*MAX)%n;
    int cur=0,res=0;
    f[0]=1;
    for (int i=1;i<=n;i++)
    {
        cur=(cur+a[i])%n;
        res+=f[cur];
        f[cur]++;
    }
    cout << res;
}