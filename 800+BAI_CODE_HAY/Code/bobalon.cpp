#include <bits/stdc++.h>
using namespace std;
#define int long long
int  a[100005];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int res=-1e10;
    int n; cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    res=max(a[1]*a[2]*a[3],a[n]*a[n-1]*a[n-2]);
    cout << res;
}
