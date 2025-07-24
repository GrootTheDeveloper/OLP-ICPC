#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,p,a,b,r,ans=1e18,res;
unordered_map <int,bool>f;

void Try(int s)
{
    res++;
    if (s==r || s==p+r)
    {
        ans=min(ans,res);
        res--;
        return;
    }
    else if (s>p+r) {res--;return;}
    Try(s+a);
    Try(s+b);
    Try(s+a+b);
    res--;
}


main()
{
    cin >> n >> p;
    cin >> a >> b >> r;
    Try((n+a)%p);
    Try((n+b)%p);
    Try((n+a+b%p));
    if (ans==1e18) cout << -1;
    else cout << ans;
}
