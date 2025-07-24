#include <bits/stdc++.h>
using namespace std;
char a[111][111];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m; cin >> n >> m;
    int res=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            cin >> a[i][j];
            if (a[i][j]=='*' && a[i-1][j]!='*' && a[i][j-1]!='*') res++;
        }
    return cout << res,0;
}
