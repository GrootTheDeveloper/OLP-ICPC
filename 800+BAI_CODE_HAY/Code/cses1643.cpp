#include <bits/stdc++.h>
#define ll long long
#define maxn 200005
ll f[maxn],n,ai;
using namespace std;

int main()
{
    ll ans = INT_MIN,k=0;
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> ai;
        f[i]=f[i-1]+ai;

        cout << k << " " << f[i] << endl;
        ans=max(ans,f[i]-k);
        k=min(k,f[i]);
    }
    cout << ans;
    return 0;
}
