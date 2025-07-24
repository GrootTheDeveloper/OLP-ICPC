//https://codeforces.com/gym/512327/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[1000006][3],f[1000006][3],n;


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i][1] >> a[i][2];
    f[1][1]=a[1][1];f[1][2]=a[1][2];
    for (int i=2;i<=n;i++)
    {
        f[i][1]=max({a[i][1],f[i-1][1],f[i-1][2]+a[i][1],f[i-2][2]+a[i][1]});
        f[i][2]=max({a[i][2],f[i-1][2],f[i-1][1]+a[i][2],f[i-2][1]+a[i][2]});
    }
    cout << max(f[n][1],f[n][2]);
}
