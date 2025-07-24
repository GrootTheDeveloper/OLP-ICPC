#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],b[100005];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int lim=INT_MIN;
    int l=1,r=1,res=0;
    while (l<=n && r<=n)
    {
        while (a[l]<lim && l<=n) l++;
        while (b[r]<lim && r<=n) r++;
        if (l>n || r>n) break;
        res++;
        lim=max(a[l],b[r]);
        l++;r++;
    }
    cout << res;
}
