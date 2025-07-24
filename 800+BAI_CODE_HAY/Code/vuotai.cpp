#include <bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k; cin >> n >> k;
    int s=0,MAX=0,ai;
    for (int i=1;i<=n;i++)
    {
        cin >> ai;
        s+=ai;
        MAX=max(MAX,ai);
    }
    cout << s-MAX+max(0ll,MAX-k)+1;
}
