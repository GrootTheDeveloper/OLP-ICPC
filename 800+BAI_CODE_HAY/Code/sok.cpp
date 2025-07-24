#include <bits/stdc++.h>
#define int long long
using namespace std;
int call(int n)
{
    return n/3+n/7+n/5-n/15-n/21-n/35+n/105;
}
main()
{
    int k; cin >> k;
    int l=1,r=1e18,res;
    while (l<r)
    {
        int mid=(l+r)/2;
        int x=call(mid);
        if (x==k) {res=mid;break;}
        if (x>k) r=mid-1;
        else l=mid+1;
        if (l>=r) res=l;
    }
    while (!(res%3==0 || res%5==0 || res%7==0)) res--;
    cout << res;

}
