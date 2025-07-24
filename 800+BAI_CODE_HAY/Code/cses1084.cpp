#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],b[200005];

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,k; cin >> n >> m >> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=m;i++) cin >> b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int i=1,j=1,res=0;
    while (i<=n && j<=m)
    {
        if (b[j]>=a[i]-k && b[j]<=a[i]+k) {res++;i++;j++;continue;}
        if (b[j]<a[i]-k) j++;
        else if (a[i]+k<b[j]) i++;

    }
    cout << res;
}
