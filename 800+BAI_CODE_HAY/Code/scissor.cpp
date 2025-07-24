#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
    int n,m; cin >> n >> m;
    int k1=min(n,m)-1,k2;
    k2=((m==k1)?k1-1:k1);
    int res=0;
    n--;m-=2;
    res=n*(n+1)/2-(n-k1)*(n-k1+1)/2;
    res=res+m*(m+1)/2-(m-k2)*(m-k2+1)/2;
    cout << res;

}
