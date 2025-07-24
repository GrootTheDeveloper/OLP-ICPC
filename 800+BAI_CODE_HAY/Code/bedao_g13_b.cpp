#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],l[100005],r[100005],pre[100005],n;

void build()
{
    int MAX=0,MIN=1e18;
    for (int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+a[i];
        MIN=min(MIN,pre[i]-MAX);
        MAX=max(pre[i],MAX);
        l[i]=MIN;
    }
    MAX=0;MIN=1e18;
    for (int i=n;i>0;i--)
    {
        pre[i]=pre[i+1]+a[i];
        MIN=min(MIN,pre[i]-MAX);
        MAX=max(pre[i],MAX);
        r[i]=MIN;
    }
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum+=a[i];
    }
    build();
    int res=-1e18;
    for (int i=1;i<n;i++)
    {
        res=max(sum -2*(l[i]+r[i+1]),res);
    }
    cout << res;
}
