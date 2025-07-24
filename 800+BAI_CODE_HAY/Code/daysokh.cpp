#include <bits/stdc++.h>
using namespace std;
#define int long long

bool us[100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    if (n > 2000) return 0;
    vector <int> vec;
    vec.push_back(0); vec.push_back(1);
    us[1] = us[0] = true;
    for (int i = 2; vec.size() <= n; i++)
    {
        bool check = true;
        for (int c : vec)
        {
            int k = i - c;
            if (k <= c && us[c - k]) check = false;
        }
        if (check) vec.push_back(i), us[i] = true;
    }
    for (int c : vec) cout << c << ' ';
}
