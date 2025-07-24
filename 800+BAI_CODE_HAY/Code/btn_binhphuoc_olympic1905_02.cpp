#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m; cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    while (m--)
    {
        int x;
        cin >> x;
        cout << upper_bound(a+1,a+n+1,x)-a-1 << ' ';
    }
}
