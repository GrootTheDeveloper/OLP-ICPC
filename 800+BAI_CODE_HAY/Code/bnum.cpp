#include <bits/stdc++.h>
using namespace std;
#define int long long


bool nto(int n)
{
    if (n<2) return false;
    for (int i=2;i<=sqrt(n);i++) if (n%i==0) return false;
    return true;
}
void solve(int n)
{
    int x=0;
    while (n) x+=pow(n%10,2),n/=10;
    if (nto(x)) cout << 1; else cout << -1;
    cout << '\n' << x;
}
main()
{
    int n; cin >> n;
    solve(n);
}
