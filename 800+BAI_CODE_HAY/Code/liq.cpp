#include <bits/stdc++.h>
using namespace std;
int a[1005],f[1005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,res=1; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i],f[i]=1;

    for (int i=2;i<=n;i++)
        for( int j=1;j<i;j++)
            if (a[i]>a[j]) f[i]=max(f[i],f[j]+1), res=max(res,f[i]);
    return cout << res,0;

}
