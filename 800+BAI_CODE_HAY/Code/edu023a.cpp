#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
    freopen("HOAHOC.INP","r",stdin);
    freopen("HOAHOC.OUT","w",stdout);
    int x,y; cin >> x >> y;
    cout << min(x/3,(y*2)/4);
}
