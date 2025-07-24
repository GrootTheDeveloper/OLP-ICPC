#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[40],res=1e18*1ll,s1,s2,n;
void dq(int i)
{
    if (i==n+1) return res=min(res,abs(s1-s2)),void();
    s1+=a[i];
    dq(i+1);
    s1-=a[i];
    s2+=a[i];
    dq(i+1);
    s2-=a[i];
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    dq(1);
    cout << res;
}
