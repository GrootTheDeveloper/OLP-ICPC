#include <bits/stdc++.h>
using namespace std;
#define int long long
int sum(int n)
{
    int res=0;
    while (n!=0) res++,n/=10;
    return res;
}
void solve()
{
    int x; cin >> x;
    int k=sum(x),s=x+k;
    if (k!=sum(s)) s++;
    cout << s << '\n';
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q; cin >> q;
    while (q--) solve();
}
