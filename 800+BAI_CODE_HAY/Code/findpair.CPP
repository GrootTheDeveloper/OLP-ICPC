#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000006];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x; cin >> n >> x;
    for (int i=1;i<=n;i++) cin >> a[i];
    int l=1,r=n;
    while (l<r)
    {
        int k=a[l]+a[r];
        if (k==x) {cout << l << ' ' << r;exit(0);}
        if (k>x) r--;
        else l++;
    }
    cout << "No solution";

}
