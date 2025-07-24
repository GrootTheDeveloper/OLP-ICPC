#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005],res;
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    res=a[1]+1;
    for (int i=2;i<=n;i++) res+=2+abs(a[i]-a[i-1]);
    cout << res;
}
