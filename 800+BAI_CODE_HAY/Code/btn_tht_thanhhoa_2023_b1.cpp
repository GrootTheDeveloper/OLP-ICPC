#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode=1e7;

int calc(int n)
{
    int a[3]={n,n+1,n+2};
    for (int i=0;i<3;i++) if (a[i]%2==0) {a[i]/=2;break;}
    for (int i=0;i<3;i++) if (a[i]%3==0) {a[i]/=3;break;}
    return ((((a[0]%mode)*a[1])%mode)*a[2])%mode;
}
signed main()
{
    int n; cin >> n;
    cout << calc(n);
}
