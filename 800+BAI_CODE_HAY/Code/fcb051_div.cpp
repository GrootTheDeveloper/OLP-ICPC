#include <bits/stdc++.h>
using namespace std;
int a[1000005],f[1000000];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    int MAX=0;
    for (int i=1;i<=n;i++) cin >> a[i],MAX=max(MAX,a[i]);
    for (int i=1;i<=MAX;i++)
        for (int j=i;j<=MAX;j+=i)
        f[j]+=i;
    for (int i=1;i<=n;i++) cout << f[a[i]] << ' ';
    return 0;

}
