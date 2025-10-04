#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    
    vector<vector<int>> f(n + 1, vector<int>(n + 1, INT_MAX));
    // f[l][r] : số kí tự ít nhất cần thêm vào để xâu đối xứng

    for (int i = 1; i <= n; i++) {
        f[i][i] = 0;
    }
    
    for (int r = 1; r <= n; r++) {
        for (int l = r - 1; l >= 1; l--) {
            
            if (s[l] == s[r]) {
                if (l == r - 1) 
                    f[l][r] = 0;
                else {
                    f[l][r] = min(f[l][r], f[l + 1][r - 1]);
                }
            }
            else {
                f[l][r] = min(f[l + 1][r] + 1, f[l][r - 1] + 1);
            }
        }
    }

    cout << f[1][n];
}