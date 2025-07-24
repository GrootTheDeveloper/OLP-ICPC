#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[1000006];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    int cnt=1,res=0;
    a[n+1]=INT_MAX;
    for (int i=1;i<=n;i++)
        if (a[i]!=a[i+1]) res+=cnt*(cnt-1)/2,cnt=1;
        else cnt++;
    cout << res;

}
