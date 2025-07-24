#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> f(111,vector<char>(111,'.'));

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n; cin >> m >> n;
    for (int i=1;i<=m;i++)
    for (int j=1;j<=n;j++)
    {
        char x;
        cin >> x;
        if (x=='#') f[i][j]=f[i][j+1]=f[i+1][j]=f[i+1][j+1]='#';
    }
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++) cout << f[i][j];
        cout << endl;
    }

}
