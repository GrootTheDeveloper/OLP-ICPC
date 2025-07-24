#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,c; cin >> n >> c;
    int sum=0,ai;
    for (int i=1;i<=n;i++)
    {
        cin >> ai;
        sum+=ai;
    }
    cout << ((sum>=c)? "YES":"NO");
}
