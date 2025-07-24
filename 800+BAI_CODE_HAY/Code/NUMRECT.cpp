#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t,m,n;
    cin >> t;
    ll a[t+1][2];
    for (int i=1;i<=t;i++)
        cin >> a[i][0] >> a[i][1];
    for (int i=1;i<=t;i++)
    {
        ll m=a[i][0],n=a[i][1],ans;
        ans = (m*(m+1)/2)*(n*(n+1)/2);
        cout << ans << "\n";
    }
    return 0;
}
