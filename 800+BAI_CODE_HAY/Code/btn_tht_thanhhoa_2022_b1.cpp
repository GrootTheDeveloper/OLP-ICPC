#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b,c; cin >> a >> b >> c;
    cout << b/c - a/c + (a%c==0);

}
