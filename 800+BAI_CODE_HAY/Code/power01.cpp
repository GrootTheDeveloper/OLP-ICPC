#include <bits/stdc++.h>
using namespace std;
#define int long long 
int mode;
int power(int a, int b, int mode)
{
    int res=1;
    while (b)
    {
        if (b&1) res=(res*a)%mode;
        a=(a*a)%mode;
        b/=2;
    }
    return res;
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x,n,m; cin >> x >> n >> m;
    mode=m*(x-1);
    cout << (power(x,n+1,mode)-1)/(x-1);
}
