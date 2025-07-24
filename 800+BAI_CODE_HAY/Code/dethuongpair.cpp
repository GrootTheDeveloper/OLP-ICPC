#include <bits/stdc++.h>
using namespace std;
#define int long long
struct dta{int val,id;};
dta MIN;
int a[100005];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin >> n;
    int x,y,MAX=-1e9;
    for (int i=1;i<=n;i++) cin >> a[i];
    MIN.val=a[1];MIN.id=1;
    for (int i=2;i<=n;i++)
    {
        if (a[i]-MIN.val>MAX) x=MIN.id,y=i,MAX=a[i]-MIN.val;
        if (MIN.val>a[i]) MIN.val=a[i],MIN.id=i;
    }
    cout << a[x] << ' ' << a[y] << '\n';
    cout << a[y]-a[x];

}
