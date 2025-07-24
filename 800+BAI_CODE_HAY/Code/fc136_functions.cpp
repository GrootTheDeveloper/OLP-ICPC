#include <bits/stdc++.h>

using namespace std;

const int maxn = 5 + 1e5;
const int block = 500;

int n, a[maxn], l[maxn], r[maxn], q, impact[block][maxn];
long long s[maxn], f[maxn], t[block];
long long get(int i) {
    return s[i] + f[i / block];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> l[i] >> r[i];
        impact[i / block][l[i]]++;
        impact[i / block][r[i] + 1]--;
    }
    for (int b = 0; b <= n / block; ++b) {
        for (int i = 1; i <= n; ++i) {
            impact[b][i] += impact[b][i - 1];
            t[b] += (long long) impact[b][i] * a[i];
        }
    }
    cin >> q;
    while(q--) {
        int type; cin >> type;
        if (type == 1) {
            int pos, val; cin >> pos >> val;
            int blockP = pos / block + 1;
            for (int b = 0; b <= n / block; ++b) t[b] += (long long) impact[b][pos] * (val - a[pos]);
            for (int b = blockP; b <= n / block; ++b) f[b] += val - a[pos];
            for (int i = pos; i < blockP * block; ++i) s[i] += val - a[pos];
            a[pos] = val;
        }
        else {
            int L, R; cin >> L >> R;
            long long res = 0;
            int blockL = L / block + 1, blockR = R / block - 1;
            for (int b = blockL; b <= blockR; ++b) res += t[b];
            if (L / block == R / block) for (int i = L; i <= R; ++i) res += get(r[i]) - get(l[i] - 1);
            else {
                for (int i = L; i < blockL * block; ++i) res += get(r[i]) - get(l[i] - 1);
                for (int i = (blockR + 1) * block; i <= R; ++i) res += get(r[i]) - get(l[i] - 1);
            }
            cout << res << '\n';
        }
    }

    return 0;
}
