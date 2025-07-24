#include <bits/stdc++.h>
using namespace std;
int n,m,f[555][555];
int cat(int n, int m)
{
    if (n==m) return 0;
    if (f[n][m]!=-1) return f[n][m];
    int &ans=f[n][m];
    ans=1e9;
    for(int i=1;i<=m;i++) ans=min(ans,cat(n,i)+cat(n,m-i)+1);
    for(int i=1;i<=n;i++) ans=min(ans,cat(i,m)+cat(n-i,m)+1);
    return ans;
}
int main()
{
    cin >> n >> m;
    memset(f,-1,sizeof f);
    cout << cat(n,m);
    return 0;
}
