
#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    if (n<4)
    {
        cout << 0;
        exit(0);
    }
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    cout <<(a[n]-a[2])*(a[n-1]-a[1]);
}
