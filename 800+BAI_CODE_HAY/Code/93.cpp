#include <bits/stdc++.h>
using namespace std;
#define int long long

unordered_map <int, vector<int>> f;
int a[5555];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[a[i]].push_back(i);
    }
    for (int i = 1; i < n; i++) for (int j = i + 1; j <= n; j++)
        if (a[i] + a[j] <= x && f.find(x - a[i] - a[j]) != f.end())
        {
            for (int id : f[x - a[i] - a[j]])
                if (id != i && id != j)
                    return cout << i << ' ' << j << ' ' << id, 0;
        }
}
