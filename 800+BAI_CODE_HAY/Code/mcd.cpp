#include <bits/stdc++.h>
using namespace std;
#define int long long

int gcd(int a, int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
int sum(int n)
{
    int res=0;
    while (n>0) res+=n%10,n/=10;
    return res;
}

main()
{
    int a,b; cin >> a >> b;
    int n=gcd(a,b);
    int res=0;
    for (int i=1;i*i<=n;i++)
        if (n%i==0) res=max({res,sum(i),sum(n/i)});
    cout << res;

}
