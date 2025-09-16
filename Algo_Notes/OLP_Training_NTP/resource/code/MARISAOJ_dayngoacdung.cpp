#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));
    // f[i][j] : khi xét s[1..i] ta dư ra j ngoặc '('
    f[0][0] = 1;
    
    // ( ? ? ?

    /*
    f[1][1] += f[0][0] -> f[1][1] = 1
    f[2][1] += f[1][0]
    f[2][2] += f[1][1] -> f[2][2] = 1
    f[2][0] += f[1][1] -? f[2][0] = 1

    */
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (s[i] == '('  || s[i] == '?') {
                (f[i][j + 1] += f[i - 1][j]) %= mod;
            }
            if (s[i] == ')' || s[i] == '?') {
                (f[i][j] += f[i - 1][j + 1]) %= mod;
            }           
        }
    }
    cout << f[n][0];
}