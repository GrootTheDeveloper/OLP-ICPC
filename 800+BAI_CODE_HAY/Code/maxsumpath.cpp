#include <bits/stdc++.h>
using namespace std;

long long f[1005][1005],n,m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >> f[i][j];
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) f[i][j]=max(f[i-1][j],f[i][j-1])+f[i][j];
    cout << f[n][m];
    return 0;
}
