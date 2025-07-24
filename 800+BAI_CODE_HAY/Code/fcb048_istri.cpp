#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[111111];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    if (a[1]+a[2]>a[n]) cout << "KHONG";
    else cout << "CO";
}
