#include <bits/stdc++.h>
#define int long long
using namespace std;

bool bs(int n)
{
    int l=1,r=1e6;
    while (l<r)
    {
        int mid=(l+r)/2;
        int x=mid*mid*mid;
        if (x==n) return true;
        if (x>n) r=mid-1;
        else l=mid+1;
    }
    return (l*l*l==n || r*r*r==n);
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        cout << (bs(n)? "YES" : "NO") << endl;
    }
}
