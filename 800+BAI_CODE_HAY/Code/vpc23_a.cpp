#include <bits/stdc++.h>
using namespace std;

char a[111][111];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n; cin >> m >> n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++) cin >> a[i][j];
    for (int i=1;i<=m;i++)
        for (int j=3;j<=n;j++)
        if (a[i][j]=='.' && a[i][j-1]=='.' && a[i][j-2]=='.') return cout << i << ' ' << j-2,0;
}
