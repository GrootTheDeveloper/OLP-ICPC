#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[111];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x; cin >> n >> x;
    int MAX=0;
    for (int i=1;i<=n;i++) cin >> a[i],MAX=max(MAX,a[i]);
    int res=0;
    for (int i=1;i<=n;i++)
    {
        if ((MAX-a[i])%x==0) res+=(MAX-a[i])/x;
        else { res=-1;break;}
    }
    cout << res;

}
