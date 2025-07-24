#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int s=0;
    while (n--)
    {
        int ai;
        cin >> ai;
        s+=ai;
        cout << s << ' ';
    }
}
