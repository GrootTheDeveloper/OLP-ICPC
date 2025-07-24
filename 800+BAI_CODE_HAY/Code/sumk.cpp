#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k; cin >> n >> k;
    int res=-1e18,s=0;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        s+=a[i];
        if (i>=k) s-=a[i-k],res=max(res,s);
    }
    cout << res;

}

