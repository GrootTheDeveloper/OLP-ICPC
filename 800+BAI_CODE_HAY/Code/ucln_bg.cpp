#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b; cin >> a >> b;
    cout << gcd(a,b);
}
