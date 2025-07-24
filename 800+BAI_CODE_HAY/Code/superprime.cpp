#include <bits/stdc++.h>
using namespace std;
#define int long long

bool nt(int n)
{
    if (n<=3) return n>1;
    if (n%2==0 || n%3==0) return false;
    int i=5;
    while (i*i<=n)
    {
        if (n%i==0 || n%(i+1)==0) return false;
        i+=6;
    }
    return true;
}
main()
{
    int n; cin >> n;
    if (nt(n) && nt(n%10)) cout << "YES";
    else cout << "NO";
}
