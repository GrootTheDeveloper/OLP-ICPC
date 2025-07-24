#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000006];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,l; cin >> n >> l;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    int pen=0,ans=0,t=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i]<=l)
        {
            ans++;
            t+=a[i];
            pen+=t;
            l-=a[i];
        }
        else break;
    }
    cout << ans << ' ' << pen;

}
