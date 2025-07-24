#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[25005],f[25005];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n; cin >> n;
    for (int i=2;i<=n;i++) cin >> a[i];
    f[2]=a[2];
    f[3]=a[2]+a[3];
    for (int i=4;i<=n;i++) f[i]=min(f[i-2]+a[i],f[i-1]+a[i]);
    cout << f[n];
}
