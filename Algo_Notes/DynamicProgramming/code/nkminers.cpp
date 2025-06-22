#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 7;

int code(char c) {
    return (c == 'M' ? 1 : (c == 'F' ? 2 : (c == 'B' ? 3 : 0)));
}

int energy(int a, int b, int c) {
    return (a != 0) + (b != 0 && b != a) + (c != 0 && c != a && c != b);
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0), cout.tie(0);
    int n; cin >> n;
    vector<char> s(n + 1);
    for (int i = 1; i <= n; i++) cin >> s[i];

    int f[n + 1][4][4][4][4];
    for (int i = 0; i <= n; i++)
    for (int a1 = 0; a1 < 4; a1++)
        for (int a2 = 0; a2 < 4; a2++)
            for (int b1 = 0; b1 < 4; b1++)
                for (int b2 = 0; b2 < 4; b2++)
                    f[i][a1][a2][b1][b2] = -oo;

    int t = code(s[1]);
    f[1][t][0][0][0] = 1;
    f[1][0][0][t][0] = 1;

    for (int i = 2; i <= n; i++) {
        int cur = code(s[i]);
        for (int t1 = 0; t1 <= 3; t1++) {
            for (int t2 = 0; t2 <= 3; t2++) {
                for (int t3 = 0; t3 <= 3; t3++) {
                    for (int t4 = 0; t4 <= 3; t4++) {
                        f[i][cur][t1][t3][t4] = max(f[i][cur][t1][t3][t4],
                                                    f[i - 1][t1][t2][t3][t4] + energy(cur, t1,t2));

                        f[i][t1][t2][cur][t3] = max(f[i][t1][t2][cur][t3],
                                                    f[i - 1][t1][t2][t3][t4] + energy(cur,t3,t4));
                    }
                }
            }
        }
    }


    int ans = 0;
    for (int a1 = 0; a1 < 4; ++a1)
        for (int a2 = 0; a2 < 4; ++a2)
            for (int b1 = 0; b1 < 4; ++b1)
                for (int b2 = 0; b2 < 4; ++b2)
                    ans = max(ans, f[n][a1][a2][b1][b2]);
    cout << ans;
}