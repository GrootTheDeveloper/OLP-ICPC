#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    priority_queue <int, vector<int>, greater<int>> q;
    int s = 0;
    for (int i = 1; i <= n; i++)
    {
        int ai; cin >> ai;
        q.push(ai);
        s += ai;
        while (s < 0) s += abs(q.top()), q.pop();
    }
    cout << q.size();
}
