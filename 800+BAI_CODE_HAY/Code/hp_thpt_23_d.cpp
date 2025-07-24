#include <bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[1000006],k;
void sol()
{
    if (k%2==0) return cout << '0',void();
    sort(a+1,a+n+1);
    int l=1,r=n;
    while (l<r)
    {
        if (a[l]+a[r]==k) break;
        if (a[l]+a[r]>k) r--;
        else l++;
    }
    if (l>=r) cout << 0;
    else cout << 1;
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i=1;i<=n;i++) cin >> a[i];
        sol();
    }
}


