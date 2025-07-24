#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
bool f[200005];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k; cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int x=1;x<=k;x++)
    {
        int i; cin >> i;
        f[i]=true;
    }
    for (int i=1;i<=n;i++) cout << a[i]+k-(f[i]) << ' ';
}
