#include <bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q; cin >> q;
    while (q--)
    {
        int t,k,n; cin >> t >> k >> n;
        if (n<=t) {cout << (n==t) << endl;continue;};
        cout << (n-t)/k+1 << endl;
    }
}
