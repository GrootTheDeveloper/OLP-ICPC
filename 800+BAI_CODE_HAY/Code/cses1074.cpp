#include <bits/stdc++.h>
using namespace std;
int a[200005];

main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    if (n==1) return cout << 0,0;
    long long k=a[n/2+1],res=0;
    for (int i=1;i<=n;i++) res+=abs(a[i]-k);
    cout << res;
}
