#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000006];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    if (n<=2)
    {
        cout << "YES";
        exit(0);
    }
    for (int i=3;i<=n;i++) if (a[i]-a[i-1]!=a[i-1]-a[i-2]) {cout << "NO";exit(0);}
    cout << "YES";
}
