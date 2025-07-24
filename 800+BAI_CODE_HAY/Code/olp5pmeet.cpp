#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    double x1,x2,v1,v2; cin >> x1 >> x2 >> v1 >> v2;
    if (x1>x2) swap(x1,x2),swap(v1,v2);
    if (v1==v2 && x1!=x2) return cout << -1,0;
    if (v1<=0 && v2>=0) return cout << -1,0;
    cout << fixed << setprecision(4) << abs((x2-x1)/(v1-v2));



}
