#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    int x;
    while (t--) 
    {
        cin >> x;
        cout << (int)sqrt(x)*2+1;
        cout << '\n';
    }
}
