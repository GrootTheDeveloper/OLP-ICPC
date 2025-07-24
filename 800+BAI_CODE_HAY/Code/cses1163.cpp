#include <bits/stdc++.h>
using namespace std;
#define int long long


main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x,n,pos; cin >> x >> n;
    priority_queue <int> q;
    unordered_map <int,int> f;
    set <int> s;
    s.insert(0);
    s.insert(x);
    while (n--)
    {
        cin >> pos;
        auto it=s.upper_bound(pos);
        auto l=it;
        l--;
        int k=*it-pos,h=pos-(*l);
        f[*it-(*l)]--;
        f[k]++;f[h]++;
        q.push(k);q.push(h);
        while (!f[q.top()]) q.pop();
        cout << q.top() << ' ';
        s.insert(pos);


    }
}
