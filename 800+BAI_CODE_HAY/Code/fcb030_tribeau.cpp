#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int a,b,c,d; cin >> a >> b >> c >> d;
    if (abs(a-b)<=d && abs(a-c)<=d && abs(b-c)<=d)cout << "Yes";
    else cout << "No";
}
