#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,d,a[100005];

void sub1()
{
    int res=0;
    for (int i=1;i<=n-2;i++)
    for (int j=i+1;j<=n-1;j++)
    for (int k=j+1;k<=n;k++)
    if (a[i]-a[j]>=d && a[j]-a[k]>=d) res++;
    cout << res;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> d;
    for (int i=1;i<=n;i++) cin >> a[i];
    if (n<=100) sub1();
}
