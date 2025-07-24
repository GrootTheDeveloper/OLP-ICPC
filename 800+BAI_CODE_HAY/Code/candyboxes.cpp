#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i],a[i]+=a[i-1];
    int q; cin >> q;
    while (q--)
    {
        int k; cin >> k;
        int it=upper_bound(a+1,a+n+1,k)-a;
        cout << it << endl;
    }
}
