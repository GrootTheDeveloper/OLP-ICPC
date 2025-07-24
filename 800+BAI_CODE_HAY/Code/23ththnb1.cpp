#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
    int l,r,t;
    cin >> l >> r >> t;
    if (t<=l*2) return cout << 0,0;
    int temp=t-l;
    if (temp>r)
    {
        l+=temp-r;
        if (l>r) return cout << 0,0;
        return cout << (r-l+1)/2,0;
    }
    else
    {
        cout << (temp-l+1)/2;
    }
}
