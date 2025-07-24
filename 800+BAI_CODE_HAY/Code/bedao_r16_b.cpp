#include <bits/stdc++.h>
using namespace std;
#define int long long
struct data{
    int fi,se;
};
data a[111111];
bool comp(data m, data n)
{
    return m.fi*m.se>n.fi*n.se;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k; cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i].fi;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i].se;
        if (a[i].se>a[i].fi) swap(a[i].se,a[i].fi);
    }
    sort(a+1,a+n+1,comp);
    if (k<=a[1].fi-a[1].se) a[1].se+=k;
    else
    {
        int temp=a[1].fi-a[1].se;
        k-=temp;
        a[1].se=a[1].fi;
        a[1].fi+=k/2;
        a[1].se+=(k/2+(k%2==1));
    }
    int s=0;
    for (int i=1;i<=n;i++)
        s+=a[i].fi*a[i].se;
    cout << s;
}

