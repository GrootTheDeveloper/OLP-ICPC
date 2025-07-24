#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
    int l,r; cin >> l >>r;
    if (l<3) l=3; else l++;
    int res=r*(r-1)/2-l*(l-1)/2;
    int x=5;
    if (x<l) x=x+(l-x)/3*3;
    while (x<l) x+=3;
    while (x<r) res-=x,x+=3;
    cout << res;

}
