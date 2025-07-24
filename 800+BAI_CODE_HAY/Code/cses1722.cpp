#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode=1e9+7;
int r[4]={0,1,1,1},t[4]={0,1,1,1},g[4];

void mp(int x[], int y[], int z[])
{
    g[0]=(x[0]*y[0]+x[1]*y[2])%mode;
    g[1]=(x[0]*y[1]+x[1]*y[3])%mode;
    g[2]=(x[2]*y[0]+x[3]*y[2])%mode;
    g[3]=(x[2]*y[1]+x[3]*y[3])%mode;
    z[0]=g[0];z[1]=g[1];z[2]=g[2];z[3]=g[3];
}
main()
{
    int n; cin >> n;
    if (n==0) {
        cout << n;
        exit(0);
    }
    n--;
    while (n)
    {
        if (n&1) mp(r,t,r);
        mp(t,t,t);
        n>>=1;
    }
    cout << r[2]%mode;
}
