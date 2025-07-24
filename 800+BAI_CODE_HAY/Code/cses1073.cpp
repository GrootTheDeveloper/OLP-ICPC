#include <bits/stdc++.h>
using namespace std;
vector <int> f;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    while (n--)
    {
        int ai;
        cin >> ai;
        auto it=upper_bound(f.begin(),f.end(),ai);
        if (it==f.end()) f.push_back(ai);
        else f[it-f.begin()]=ai;
    }
    return cout << f.size(),0;
}
