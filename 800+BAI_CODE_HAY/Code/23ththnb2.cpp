#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[5555];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,t; cin >> n >> t;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    int res=1e18;
    for (int i=1;i<=n-2;i++)
    {
       int l=i+1,r=n;
       while (l<r)
       {
           int s=a[i]+a[l]+a[r];
           if (abs(s-3*t) < abs(res-3*t)) res=s;
           else if (abs(s-3*t)==abs(res-3*t)) res=max(res,s);
           if (s<3*t) l++;
           else r--;
       }
    }
    cout << res;
    return 0;

}
