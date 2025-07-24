#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string  x,y;
    cin >> x >> y;
    x='0'+x;
    y='0'+y;
    int n=x.size()-1,m=y.size()-1;
    vector<vector<int>> f(n+1,vector<int> (m+1,0));
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
        if (x[i]==y[j]) f[i][j]=f[i-1][j-1]+1;
        else f[i][j]=max(f[i-1][j],f[i][j-1]);
    cout << f[n][m];

}
