#include <bits/stdc++.h>
using namespace std;
int a[(int)2e5+5];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    long long  res=1;
    for (int i=1;i<=n;i++)
        if (a[i]<=res) res+=a[i];
    return cout << res,0;

}
