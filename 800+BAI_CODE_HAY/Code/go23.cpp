#include <bits/stdc++.h>
using namespace std;
#define int long long 


main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int t,x; cin >> t;
    while (t--)
    {
        cin >> x;
        if (x==1) cout << 2 << '\n';
        else if (x%3==0) cout << x/3 << '\n';
        else cout << x/3+1 << '\n';
    }
}
