#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <bool> sol,res(20);
int n,m,v[20],w[20],ans;
void check()
{
    int M=0,kq=0;
    for (int i=1;i<=n;i++) if (res[i]) M+=w[i],kq+=v[i];
    if (M<=m && kq>ans) sol=(res),ans=kq;
}
void Try(int i)
{
    if (i==n+1) {check();return;};
    res[i]=1;
    Try(i+1);
    res[i]=0;
    Try(i+1);
}
main()
{
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> w[i] >> v[i];
    Try(1);
    int cnt=0;
    for (int i=1;i<=n;i++) cnt+=(sol[i]);
    cout << cnt << endl;
    for (int i=1;i<=n;i++) if (sol[i]) cout << i << ' ';
}
