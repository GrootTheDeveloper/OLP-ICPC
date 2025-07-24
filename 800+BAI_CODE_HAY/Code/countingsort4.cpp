#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <string> v[101];
string s;
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int x;
    for (int i=1;i<=n;i++)
    {
        cin >> x >> s;
        if (i<=n/2) s="-";
        v[x].push_back(s);
    }
    int cnt=0;
    for (int i=0;i<=100;i++)
    for (string c : v[i])
        cout << c << ' ';
}
