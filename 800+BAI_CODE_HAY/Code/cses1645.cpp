#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
int ds[N],a[N];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        int k=i-1;
        while (a[k]>=a[i])
            k=ds[k];
        ds[i]=k;
        cout << ds[i] << ' ';
    }
    return 0;
}
