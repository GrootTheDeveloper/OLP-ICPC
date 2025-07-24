#include <bits/stdc++.h>
using namespace std;
#define int long long
int pre[1111],a[1000006],n,k;

void sub1()
{
    int res=0;
    for (int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for (int i=1;i<=n;i++) for (int j=i;j<=n;j++)
    if ((pre[j]-pre[i-1])%k==0) res++;
    cout << res;
}
unordered_map <int,int> f;
void sub2()
{
    int sum=0,res=0;
    for (int i=1;i<=n;i++)
    {
        sum+=a[i];
        int l=sum%k;
        if (l==0) res++;
        res+=f[l];
        if (l!=0)
        {
            int x=0;
            if (l>0)
                x=(k-l)*(-1);
            else if (l<0)
                x=(k-abs(l));
            res+=f[x];
        }
        f[l]++;

    }
    cout << res;
}


main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i],a[i]%=k;
    if (n<=1000) sub1();
    else sub2();
}
