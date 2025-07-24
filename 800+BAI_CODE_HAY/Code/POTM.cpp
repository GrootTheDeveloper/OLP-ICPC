#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100005
ll f[maxn];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll n,q,ai;
    cin >> n >> q;
    f[0]=0;
    for (int i=1; i<=n; i++)
    {
        cin >> ai;
        f[i]=f[i-1]+ai;
    }

    int type,x,k;
    while (q--)
    {
        cin >> type >> x >> k;
        if (type) cout << f[x]-f[x-k] << endl;
        else cout << f[k] << endl;
    }
    return 0;
}
