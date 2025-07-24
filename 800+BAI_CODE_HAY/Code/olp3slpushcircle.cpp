#include <bits/stdc++.h>
using namespace std;
#define int long long


main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s; cin >> s;
    deque <char> q;
    for (char c : s)
    {
        q.push_back(c);
        char k=q.front();
        q.pop_front();
        q.push_back(k);
    }
    while (q.size()) cout << q.front(),q.pop_front();
}
