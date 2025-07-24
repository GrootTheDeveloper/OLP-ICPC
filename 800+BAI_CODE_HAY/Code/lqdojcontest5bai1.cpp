#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int a,b; cin >> a >> b;
    if (a>8) a=15-a+1;
    if (a%2==1)
    {
        if (b%2==0 && (b<a || b>15-a))
        cout << "trang";
        else cout << "den";
    }
    else
    {
        if (b%2==0 || (b>=a && b<=15-a+1))
        cout << "trang";
        else cout << "den";
    }
}
