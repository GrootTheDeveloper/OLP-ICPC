#include <bits/stdc++.h>
using namespace std;
vector <int> d;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m,p; cin >> n >> m >> p;
    for (int i=1;i<=n;i++)
    {
        int x,y; cin >> x >> y;
        y-=x;
        d.push_back(y);
    }
    sort(d.begin(),d.end());
    return cout << d[m-1]+1,0;
}
