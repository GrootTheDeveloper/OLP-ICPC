#incldue <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int par[N], sz[N], S[N], a[N];
map<int,int> cnt;
void make_set(int n)
{
    for (int i = 1; i <= n; i++)
        par[i] = i, sz[i] = S[i];
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    vector<int> b;
    for (int i = 1; i <= q; i++)
    {
        cin >> Q[i];
        b.push_back(Q[i]);
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    int lim = 0;
    if (b[0] != 1)
        S[++lim] = b[0] - 1;
    for (int i = 1; i <= sz(b); i++){
        pos[i] = ++lim;
        S[lim] = 1;
        if (i < sz(b)){
            if (b[i] - b[i - 1] > 1){
                ++lim;
                S[lim] = b[i] - b[i - 1] - 1;
            }
        }
    }
    if (b.back() != n)
        S[++lim] = n - b.back();
    make_set(lim);
}
