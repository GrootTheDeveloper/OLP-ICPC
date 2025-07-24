#include <bits/stdc++.h>
using namespace std;
int a[111];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    return cout << a[n]-a[1],0;
}
