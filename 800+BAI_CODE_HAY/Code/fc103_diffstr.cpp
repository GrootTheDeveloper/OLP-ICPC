#include <bits/stdc++.h>
using namespace std;
const int base = 311;
string s;
namespace sub1
{
    #define int long long
    unordered_map<int,int> f;
    void work()
    {
        int n = s.size();
        s = " " + s;
        for (int i = 1; i <= n; i++)
        {
            int cur = 0;
            for (int j = i; j <= n; j++)
                cur = cur * base + s[j], f[cur] = true;
        }
        cout << f.size();
    }
}
namespace sub2
{
    int child[13000007][2];
    void work()
    {
        memset(child, -1, sizeof(child));
        int n = s.size();
        s = " " + s;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int pos = 0;
            for (int j = i; j <= n; j++)
            {
                if (child[pos][s[j] - 'a'] == -1)
                    child[pos][s[j] - 'a'] = ++ans;
                pos = child[pos][s[j] - 'a'];
            }
        }
        cout << ans;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    if ((int)s.size() <= 1000) sub1::work();
    else sub2::work();
}
