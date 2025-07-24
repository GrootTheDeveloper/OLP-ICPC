#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],c[100005];

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m; cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=m;i++)
    {
        int b; cin >> b;
        c[i]=lower_bound(a+1,a+n+1,b)-a-1;
    }
    for (int i=1;i<=m;i++) cout << c[i] << ' ';
}
