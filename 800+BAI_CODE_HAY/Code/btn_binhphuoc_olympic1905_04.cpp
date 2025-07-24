#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

signed main()
{
    int x,n,k; cin >> x >> n >> k;
    int m=k*(x+k*x)/2;
    cout << ((m>n)? m-n : 0);
}
