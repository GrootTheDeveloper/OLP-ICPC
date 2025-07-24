#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
bool stt(ll n)
{
    ll s=0,k=n;
    while (k>0)
    {
        s=s*10+k%10;
        k/=10;
    }
    if (gcd(n,s)==1) return true;
    return false;
}
int main()
{
    ll t;cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (stt(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
    return 0;
}
