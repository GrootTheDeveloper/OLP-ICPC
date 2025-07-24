#include <bits/stdc++.h>
using namespace std;
#define int long long
int m,n,q,k,a[1111][1111];

void sub1()
{
    unordered_map <int,int> f;
    int ai;
    for (int i=1;i<=n;i++) cin >> ai, f[ai%k]++;
    while (q--)
    {
        int x; cin >> x; cout << f[x] << '\n';
    }
}
int f[1111][1111];
void sub2()
{
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >> a[i][j],a[i][j]%=k;
    while (q--)
    {
        //memset(f,0,sizeof(f));
        int x; cin >> x;
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) f[i][j]=max({f[i][j-1],f[i-1][j],f[i-1][j-1]})+(a[i][j]==x);
        cout << f[n][m] << '\n';
    }
}
int cnt[333];
void sub3()
{

    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >> a[i][j],a[i][j]%=k;
    for (int x=0;x<=k;x++)
    {
        for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) f[i][j]=max({f[i][j-1],f[i-1][j],f[i-1][j-1]})+(a[i][j]==x);
        cnt[x]=f[n][m];
    }
    while (q--)
    {
        int x; cin >> x;
        cout << cnt[x] << '\n';
    }
}


main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("ROBOT.INP","r",stdin);
    freopen("ROBOT.OUT","w",stdout);
    cin >> n >> m >> q >> k;
    if (m==1) sub1();
    else if (m==2) sub2();
    else if (k<=300) sub3();

}
