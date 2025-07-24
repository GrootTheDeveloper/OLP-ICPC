#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q,k,a[1111][1111];

void sol1()
{
    unordered_map <int,int> f;
    int ai;
    for (int i=1;i<=n;i++) cin >> ai,f[ai%k]++;
    int x;
    while (q--)
    {
        cin >> x;
        cout << f[x] << '\n';
    }
}
void sol2()
{
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >> a[i][j],a[i][j]=a[i][j]%k;
    int x;
    vector <vector<int>> f(n+3,vector<int> (m+5,0));
    while (q--)
    {
        cin >> x;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            f[i][j]=max({f[i-1][j-1],f[i-1][j],f[i][j-1]})+(a[i][j]==x);
        cout << f[n][m] << '\n';
    }
}
void sol3()
{
    unordered_map <int,int> cnt;
    vector <vector<int>> f(n+3,vector<int> (m+5,0));
    for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) cin >> a[i][j],a[i][j]=a[i][j]%k;
    for (int l=0;l<=k;l++)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                f[i][j]=max({f[i-1][j-1],f[i-1][j],f[i][j-1]})+(a[i][j]==l);
        cnt[l]=f[n][m];
    }
    int x;
    while (q--)
    {
        cin >> x;
        cout << cnt[x] << '\n';
    }
}

main()
{

    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> m >> q >> k;
    if (m==1) sol1();
    else if (m==2) sol2();
    else if (n+m+k<=1000) sol3();

}
