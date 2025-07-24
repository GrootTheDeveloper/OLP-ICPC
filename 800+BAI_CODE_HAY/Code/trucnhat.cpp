#include <bits/stdc++.h>
using namespace std;
#define int long long
int pre[5000001],a[1000001],N;

void sie()
{
    for (int i=2;i<=N;i++)
        for (int j=i;j<=N;j+=i) pre[j]+=i;

}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    sie();
    int n,res=0,ai; cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        N=max(N,a[i]);
    }
    sie();
    for (int i=1;i<=n;i++) res+=(pre[a[i]]+1<a[i]*2);
    cout << res;
}
