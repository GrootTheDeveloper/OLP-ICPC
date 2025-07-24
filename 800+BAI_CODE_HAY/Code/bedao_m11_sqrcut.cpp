#include <bits/stdc++.h>
using namespace std;
#define int long long

int cet(int a, int b)
{
    if (a<b) swap(a,b);
    int res=0;
    while (b!=0)
    {
        res+=a/b;
        a=a%b;
        swap(a,b);
    }
    return res;
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int a,b; cin >> a >> b;
        cout << cet(a,b) -1 << '\n';
    }
}
