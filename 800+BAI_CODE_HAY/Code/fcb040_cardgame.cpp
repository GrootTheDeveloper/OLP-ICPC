#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k; cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    int x=0,y=0,i=0,j=n;
    while(k--)
    {
        i++;j--;
        x+=a[i];y+=a[j];
    }
    cout << x << ' ' << y;
}
