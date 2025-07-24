#include <bits/stdc++.h>
using namespace std;
#define int long long
deque<int> q;
int res,n,t,ai,s;
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> t;
    for (int i=1;i<=n;i++)
    {
        cin >> ai;
        s+=ai;
        q.push_back(ai);
        while (s>t)
        {
            s-=q.front();
            q.pop_front();
        }
        res=max(res,(int)q.size());

    }
    cout << res;
}
