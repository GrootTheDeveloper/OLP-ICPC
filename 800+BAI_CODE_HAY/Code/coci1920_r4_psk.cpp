#include <bits/stdc++.h>
#define int long long
using namespace std;
struct dta{int val,id;};
bool cmp1(dta a, dta b) {return a.val>b.val;};
bool cmp2(dta a, dta b) {return a.id<b.id;};
dta a[1111];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int v=0;
    for (int i=1;i<=n;i++)
    {
        int vt;
        cin >> vt >> a[i].val;
        v+=vt;
        a[i].id=i;
    }
    sort(a+1,a+n+1,cmp1);
    int res=0;
    for (int i=1;i<=n;i++)
    {
        if (a[i].val<=v) v-=a[i].val;
        else a[i].val=v,v=max(0ll,v-a[i].val);
        if (a[i].val==0) res++;
    }
    cout << res << endl;
    sort(a+1,a+n+1,cmp2);
    for (int i=1;i<=n;i++) cout << a[i].val << ' ';

}
