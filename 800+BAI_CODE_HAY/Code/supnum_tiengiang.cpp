#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000006];


bool nto(int n)
{
    if (n<2) return false;
    for (int i=2;i<=sqrt(n);i++) if (n%i==0) return false;
    return true;
}

bool check(int n)
{
    int k=0;
    int lim=trunc(sqrt(n));
    for (int i=2;i<=lim;i++)
    {
        if (n%i==0) k+=i;
        while(n%i==0) n/=i;
    }
    if (n!=1) k+=n;
    return (k%5==0);
}
void sub1()
{
    int dem=0;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        if (check(a[i])) cout << a[i] << ' ',dem++;
    }
    if (dem==0) cout << -1;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    if (n<=500) sub1();

    /*
    int dem=0;
    for (int i=1;i<=31622;i++)
    {
        if (nto(i) && i%5==3) cout << i << endl,dem++;
    }
    cout << dem;*/
}
