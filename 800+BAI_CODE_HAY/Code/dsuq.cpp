#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7 + 7;
int a[N], par[N];
int st[N];
vector <int> Q[N];
int get(int x)
{
    return (x == par[x]? x : par[x] = get(par[x]));
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q, x, y, z, mode; cin >> n >> q >> x >> y >> z >> mode;
    for (int i = 1; i <= q; i++)
    {
        int l = min(i % n + 1, i * i % n + 1);
        int r = max(i % n + 1, i * i % n + 1);
        Q[r].push_back(l);
    }
    a[1] = x;
    long long ans = 0;
    vector <int> st;
    st.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        long long val = (a[i - 1] * y + z) % mode;
        a[i] = val;
        par[i] = i;
        while (st.size())
        {
            if (a[st.back()] > a[i]) break;
            else par[st.back()] = i, st.pop_back();
        }
        st.push_back(i);
        for (int x : Q[i])
            ans += a[get(x)];
    }
    cout << ans % mode;
}
