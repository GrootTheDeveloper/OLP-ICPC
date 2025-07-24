#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+5;
int a[MAX];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k; cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i],a[i]+=k;
    for (int i=1;i<=k;i++)
    {
        int t;
        cin >> t;
        a[t]-=1;
    }
    for (int i=1;i<=n;i++) cout << a[i] << ' ';
    return 0;

}
