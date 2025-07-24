#include <bits/stdc++.h>
using namespace std;
#define mode 1000000007
#define ll long long

ll power(ll a, ll b)
{
    if (b==0) return 1;
    ll x=power(a,b/2);
    if (b%2==0) return x*x%mode;
    return x*x%mode*a%mode;
}
main()
{
    ll n;
    cin >> n;
    cout << power(2,n);
}
