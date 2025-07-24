#include <bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,k; cin >> n >> k;
    int y=min(k,n),x;
    if (y<k) x=k-y;
    else x=k-y+1,y--;
    if (x<y) cout << (y-x+1)/2;
    else cout << 0;
    return 0;
}
