#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[10000007],n,m;
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    int res=(int)1e18;
    for (int i=1;i<=n-m+1;i++) res=min(res,a[i+m-1]-a[i]);
    cout << res;

}
