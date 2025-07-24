#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool nt(ll n)
{
    if (n<3) return n>1;
    else if (n%2==0 || n%3==0) return 0;
    ll i=5;
    while (i*i<=n)
    {
        if (n%i==0 || n%(i+2)==0) return 0;
        i+=6;
    }
    return 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    if (!nt(n)) return cout << "NO",0;
    ll i=0,j= (ll) sqrt(n),k;
    while (i<=j)
    {
        k=i*i+j*j;
        if (k==n) return cout << "YES",0;
        if (k>n) j--;
        else i++;
    }
    cout << "NO";
    return 0;
}
