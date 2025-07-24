#include <bits/stdc++.h>
using namespace std;
int a[2222];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,z,w; cin >> n >> z >> w;
    for (int i=1;i<=n;i++) cin >> a[i];
    if (n==1) return cout << abs(a[1]-w),0;
    return cout << max(abs(a[n-1]-a[n]),abs(a[n]-w)),0;
}
