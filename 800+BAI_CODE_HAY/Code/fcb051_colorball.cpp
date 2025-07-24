#include <bits/stdc++.h>
using namespace std;
int f[3333][3333];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int m,n,k; cin >> m >> n >> k;
    k<<=1;
    for (int t=1;t<=k;t++)
    {
        int x,y;
        cin >> x >> y;
            for (int i=x-1; i<=x+1; i++)
            for (int j=y-1;j<=y+1;j++)
            if (t&1)
            {

                if (f[i][j]<1) f[i][j]++;
            }
            else
            {
                if (f[i][j]>-1) f[i][j]--;
            }
    }
    int t1=0,t2=0;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
        if (f[i][j]==1) t1++;
        else if (f[i][j]==-1) t2++;
    return cout << t1 << ' ' << t2,0;
}
