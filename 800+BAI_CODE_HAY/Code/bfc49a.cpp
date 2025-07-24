#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,k; cin >> n >> k;
    if (n==k) return cout << (n-1)/2,0;
    if (n>k) return cout << (k-1)/2,0;
    else cout << max((n-(k-n)+1)/2,0LL);

}
