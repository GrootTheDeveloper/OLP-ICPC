#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],f[100005];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    f[1]=a[1];
    f[2]=a[1]+a[2];
    for (int i=3;i<=n;i++)
        f[i]=max({f[i-1],f[i-2]+a[i],f[i-3]+a[i-1]+a[i]});
    cout << f[n];

}
