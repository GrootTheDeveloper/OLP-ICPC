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

    int f[n + 1][4][4][4];
    for (int i = 0; i <= n; i++) 
        for (int a = 0; a < 4; a++)
            for (int b = 0; b < 4; b++) 
                for (int c = 0; c < 4; c++)
                    f[i][a][b][c] = -1;
                    
    f[0][0][0][0] = 0;
    f[1][0][0][0] = 1;  
    for (int i = 2; i <= n; i++) {
        for (int a = 0; a < 4; a++) {
            for (int b = 0; b < 4; b++) {
                for (int c = 0; c < 4; c++) {
                    if (f[i - 1][a][b][c] == -1) continue;
                    f[i][code(s[i - 1])][b][c] = max(f[i][code(s[i - 1])][b][c], f[i - 1][a][b][c] + energy(code(s[i]), code(s[i - 1]), a));

                    f[i][b][code(s[i - 1])][a] = max(f[i][b][code(s[i - 1])][a], f[i - 1][a][b][c] + energy(code(s[i]), b, c));

                }
            }
        }
    }

    int ans = 0;
    for (int a = 0; a < 4; a++) {
        for (int b = 0; b < 4; b++) {
            for (int c = 0; c < 4; c++) {
                ans = max(ans, f[n][a][b][c]);
            }
        }
    }
    cout << ans;
}