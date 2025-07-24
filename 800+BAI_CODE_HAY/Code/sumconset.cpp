#include <bits/stdc++.h>
using namespace std;
#define int long long
deque <int> q;

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,t; cin >> n >> t;
    int ans=0,s=0;
    for (int i=1;i<=n;i++)
    {
        int ai;
        cin >> ai;
        s+=ai;
        q.push_front(ai);
        while (s>t) s-=q.back(), q.pop_back();
        ans=max(ans, (int)q.size());
    }
    cout << ans;
}
