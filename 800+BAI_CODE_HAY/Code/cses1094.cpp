#include <bits/stdc++.h>
using namespace std;
int a[200005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    long long res=0;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        if (i!=1 && a[i]<a[i-1])
        {
            res+=a[i-1]-a[i];
            a[i]=a[i-1];
        }
    }
    cout << res;
    return 0;
}
