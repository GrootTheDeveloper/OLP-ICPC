#include <bits/stdc++.h>
using namespace std;
#define MAX 1000007
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,x; cin >> n >> x;
    int f[x+1],a[n+1];
    for (int i=1;i<=n;i++)
        cin >> a[i];
    for (int i=1;i<=x;i++)
        f[i]=MAX;
    f[0]=0;
    for (int sum=1;sum<=x; sum++)
    for (int i=1;i<=n;i++)
        if (a[i]<=sum && f[sum-a[i]]+1<f[sum])  f[sum]=f[sum-a[i]]+1;
    if (f[x]==MAX) cout << -1;
    else cout << f[x];
    return 0;

}
