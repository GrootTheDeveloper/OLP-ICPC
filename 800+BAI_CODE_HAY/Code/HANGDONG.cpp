#include <bits/stdc++.h>
using namespace std;
#define maxn 1000007
#define ll long long
ll a[maxn],f[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    f[0]=0;
    f[1]=a[1];
    f[2]=a[1]+a[2];
    if (n<2) return cout << f[n],0;
    for (int i=3; i<=n; i++)
        f[i]=max(a[i-1],a[i-2])+f[i-3]+a[i];
    cout << f[n];
    return 0;

}
