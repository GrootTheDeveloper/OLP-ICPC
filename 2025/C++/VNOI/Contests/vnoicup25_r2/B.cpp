#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while(t--) {
        int n, m, x, y;
        cin >> n >> m >> y >> x;

        vector<vector<char>> a(n + 1, vector<char>(m + 1));

        // fill tren
        for (int i = 1; i <= y - 1; i++) {
            for (int j = 1; j <= m; j++) {
                a[i][j] = 'v';
            }
        }
        // fill trai
        for (int i = 1; i <= x - 1; i++) {
            a[y][i] = '>';
        }
        // fill phai
        for (int i = x + 1; i <= m; i++) {
            a[y][i] = '<';
        }
        // fill duoi
        for (int i = y + 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                a[i][j] = '^';
            }
        }

        a[y][x] = '.';
        
        if (y == 1) {
            if (x == 1) {
                a[n][m] = '<';   
                a[n - 1][m] = 'v';
                a[n][1] = '>';
            }
            else if (x == m) {
                a[n][1] = '>';
                a[n - 1][1] = 'v';
                a[n][m] = '<';
            }
            else {
                a[1][1] = 'v';
                a[2][1] = '>';
            }
        }
        if (y == n) {
            if (x == 1) {
                a[1][1] = '>';
                a[2][1] = '^';   
            }
            else if (x == m) {
                a[1][1] = '>';
                a[2][1] = '^';
            }
            else {
                a[2][1] = '^';
                a[1][1] = '>';
                a[1][m] = '<';
            }
        }

        if (x == 1) {
            if (y == 1) {
                a[n][m] = '<';   
                a[n - 1][m] = 'v';
                a[n][1] = '>';
            }
            else if (y == n) {
                a[1][1] = '>';
                a[2][1] = '^';
            }
            else {
                a[n - 1][m] = 'v';
                a[n][m] = '<';
                a[1][1] = '>';
            }
        }
        if (x == m) {
            if (y == n) {
                a[1][1] = '>';
                a[2][1] = '^';
                a[1][m] = '<';
            }
            else if (y == 1) {
                a[n][1] = '>';
                a[n - 1][1] = 'v';
            }
            else {
                a[n][1] = '^';
                a[n - 1][1] = '>';
                a[n][m] = '<';
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
}
