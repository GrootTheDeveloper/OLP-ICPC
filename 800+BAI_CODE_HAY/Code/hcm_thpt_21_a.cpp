#include <bits/stdc++.h>
using namespace std;
#define int long long

int sum(int n)
{
    int res=0;
    while (n) res++,n/=10;
    return res;
}
main()
{
    int n; cin >> n;
    int res=3;
    while (n!=0) res++,n-=sum(res);
    cout << res;
}
