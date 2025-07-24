#include <bits/stdc++.h>
using namespace std;
const int N=262155;
int a[N];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    if (n==2 && a[1]==a[2]) return cout << a[1]+1,0;
    int res=max(a[1],a[2]);
    for (int i=3;i<=n;i++)
    {
        if (a[i-1]==a[i-2])
        {
            if (a[i]==a[i-1]+1) a[i]++;
            a[i-1]++;
        }
        res=max(res,a[i]);
    }
    return cout << res,0;
}
