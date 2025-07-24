#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("O.INp","r",stdin);
    freopen("O.out","w",stdout);

    int m,n; cin >> m >> n;
    vector <vector<int>> a(m+2,vector<int> (n+2,0));
    vector <vector<int>> hang=(a),cot=(a);
    string s;
    for (int i=1;i<=m;i++)
    {
    cin >> s;
    for (int j=1;j<=n;j++)
    {
        a[i][j]=s[j-1]-'0';
        hang[i][j]=hang[i][j-1]+a[i][j];
        cot[j][i]=cot[j][i-1]+a[i][j];
    }}
    int res=0;
    for (int i=1;i<=m;i++)
    for (int j=1;j<=n;j++)
    {
        for (int x=i;x<=m;x++)
        for (int y=j;y<=n;y++)
        res+=(hang[i][y]-hang[i][j-1]==0 && hang[x][y]-hang[x][j-1]==0 && cot[j][x]-cot[j][i-1]==0 && cot[y][x]-cot[y][i-1]==0);
    }
    cout << res;
}
