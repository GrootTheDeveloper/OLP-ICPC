#include <bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int ai,n,s=0;
        cin >> n;
        while (n--) cin >> ai,s+=ai;
        if (s%2!=0) cout <<"first" << endl;
        else cout << "second" << endl;
    }
    return 0;
}
