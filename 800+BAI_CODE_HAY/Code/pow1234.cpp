#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mode 1000000007

ll power(ll a, ll b)
{
    if (b==0) return 1;
    ll x=power(a,b/2);
    if (b%2==0) return x*x%mode;
    return x*x%mode*a%mode;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a,m,t;
    cin >> t;
    while (t--)
    {
        cin >> a >> m;
        ll s=m*(m+1)/2;
        cout << power(a,s) << endl;
    }
    return 0;
}
