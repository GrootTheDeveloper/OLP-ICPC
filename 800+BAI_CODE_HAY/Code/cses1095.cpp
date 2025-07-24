//https://lqdoj.edu.vn/problem/cses1095
#include <bits/stdc++.h>
#define ll long long
const int mode=1e9+7;
using namespace std;

ll power(ll a,ll b)
{
    if (b==0) return 1;
    if (b==1) return a;
    ll x=power(a,b/2);
    if (b%2==0) return x*x%mode;
    return x*x%mode*a%mode;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll t,a,b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << power(a,b) << endl;
    }
    return 0;

}
