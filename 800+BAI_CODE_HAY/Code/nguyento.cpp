#include <bits/stdc++.h>
using namespace std;
#define int long long
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int h)
{
    return l+rd()%(h-l+1);
}
int mul(int a, int b, int mode)
{
    int res=0;
    while (b)
    {
        if (b&1) res=(res+a)%mode;
        a=(a+a)%mode;
        b/=2;
    }
    return res;
}

int Pow(int a, int b, int mode)
{
    int res=1;
    while (b)
    {
        if (b&1) res=mul(res,a,mode);
        a=mul(a,a,mode);
        b/=2;
    }
    return res;
}
bool nt(int n)
{
    if (n<3) return (n>1);
    for (int i=1;i<=100;i++)
    {
        int x=Rand(2,n-1);
        if (Pow(x,n-1,n)!=1) return false;
    }
    return true;
}
main()
{
    int k; cin >> k;
    int res=0;
    for (int i=1;i<=9;i+=2)
    {
        int x=0;
        for (int j=1;j<=k;j++) x=x*10+i;
        for (int l=0;l<=9;l++)
        if (l!=i)
        {
            int sol=x;
            sol=sol*10+l;
            sol=sol*pow(10,k)+x;
            res+=(nt(sol));
        }
    }
    cout << res;
}
