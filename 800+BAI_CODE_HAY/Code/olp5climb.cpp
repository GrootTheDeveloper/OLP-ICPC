#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,a[500005],b[500005];

void sub1()
{
    int k;
    while (q--)
    {
        int res=0;
        cin >> k;
        for (int i=1;i<=n;i++)
        {
            if (k>=a[i]) res+=a[i],k-=b[i];
            else break;
        }
        cout << res << '\n';
    }
}
int f[500005],pr[500005];
void sub2()
{
    for (int i=1;i<=n;i++) f[i]=max(f[i-1],a[i]),pr[i]=pr[i-1]+a[i];
    int k;
    while (q--)
    {
        cin >> k;
        int pos=upper_bound(f+1,f+n+1,k)-f-1;
        cout << pr[pos] << '\n';
    }
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    int sum=0;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i],sum+=b[i];
    if (sum==0) sub2();
    else if (n<=5000) sub1();


}
