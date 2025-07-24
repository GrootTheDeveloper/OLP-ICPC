#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector <int> vec;
    queue <int> q;
    for (int i = 1; i <= n; i++)
    {
        int ai; cin >> ai;
        cout << 'C';
        q.push(ai);
    }
    while (q.size())
    {
        int val = q.front(); q.pop();
        while (vec.size())
        {
            if (to_string(vec.back()) < to_string(val))
            {
                cout << 'C';
                q.push(vec.back());
                vec.pop_back();
            }else break;
        }
        cout << 'H';
        vec.push_back(val);
    }
}
