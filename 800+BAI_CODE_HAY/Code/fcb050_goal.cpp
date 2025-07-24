#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
    int n; cin >> n;
    int res=n;
    res+=(n/10)*2;
    res-=(n/15);
    res-=(n/30)*2;
    cout << res;
}
