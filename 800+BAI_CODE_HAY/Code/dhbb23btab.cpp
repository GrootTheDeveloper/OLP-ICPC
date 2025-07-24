#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n; cin >> m >> n;
    for (int i=1;i<=m;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    vector<vector<int>> c(m+1,vector<int>(n+1,0));
    vector<vector<int>> cnt(m+1,vector<int>(n+1,0));
    vector<vector<int>> pf(m+1,vector<int>(n+1,0));
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        {
            c[i][j]=a[i]*b[j];
            if (c[i][j]==1) cnt[i][j]=cnt[i-1][j-1]+1; ;
        }
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        pf[i][j]=pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1]+c[i][j];
    int res=0;
    for (int i=1;i<=m;i++)
    for (int j=1;j<=n;j++)
    {
        if (cnt[i][j]>1)
        {
            int k=cnt[i][j]-1,x=i,y=j;
            while (k--)
            {
                x--;
                y--;
                if (pf[i][j]-pf[x-1][j]-pf[i][y-1]+pf[x-1][y-1]==0) res++;
            }

        }
    }
    return cout << res,0;
}
