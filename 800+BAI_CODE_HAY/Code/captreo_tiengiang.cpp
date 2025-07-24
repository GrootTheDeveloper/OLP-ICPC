#include <bits/stdc++.h>
using namespace std;
#define int long long
int ai,n,f[10005],pos[10005];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> ai;
        pos[ai]=i;
    }
    for (int i=1;i<=n;i++)
    {
        f[i]=1;
        for (int j=1;j<i;j++)
        {
            if (pos[j]<pos[i]) f[i]=max(f[i],f[j]+1);
        }
    }
    int res=0;
    for (int i=1;i<=n;i++) res=max(res,f[i]);
    cout << res;
}
