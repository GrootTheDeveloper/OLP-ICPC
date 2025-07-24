#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000006];
void sub1()
{
    int res=0;
    for (int i=n;i>=1;i--)
    {
        int k=1;
        while (a[i-1]==a[i]) k++,i--;
        res+=(k-1)*(a[i]*2+a[i-1])+a[i]+a[i-1];
    }
    cout << res;
}
void sub2()
{
    int res=0;
    for (int i=1;i<=n;i++) res+=a[i]+a[i+1];
    cout << res;
}
void sub3()
{
    int res=0;
    while (n)
    {
        int pos=1;
        for (int i=1;i<=n;i++) if (a[i]>a[pos]) pos=i;
        res+=a[pos]+a[pos-1]+a[pos+1];
        for (int i=pos;i<n;i++) a[i]=a[i+1];
        a[n]=0;
        n--;
    }
    cout << res;
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    int dec=0,inc=0;
    cin >> a[1];
    for (int i=2;i<=n;i++)
    {
        cin >> a[i];
        if (a[i]>=a[i-1]) inc++;
        if (a[i]<=a[i-1]) dec++;
    }
    if (inc==n-1) sub1();
    else if (dec==n-1) sub2();
    else if (n<=1000) sub3();
}
