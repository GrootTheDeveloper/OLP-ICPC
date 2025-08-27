#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9 + 7;

int main() {
    int n, p, k;
    cin >> n >> p >> k;
    vector<int>a(n + 1, 0), b(n + 1, 0);
    int r; cin >> r;
    for (int i = 1; i <= r; i++) {
        int x; cin >> x;
        a[x] = 1;
    }
    int s; cin >> s;
    for (int i = 1; i <= s; i++) {
        int x; cin >> x;
        b[x] = 1;
    }
    // f[i][j][kA][kB]

    int f[n + 1][p + 1][k + 1][k + 1];

    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= p; j++) 
            for (int kA = 0; kA <= k; kA++) 
                for (int kB = 0; kB <= k; kB++) 
                    f[i][j][kA][kB] = -1;

    f[0][0][0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= p; j++) {
            for (kA = 0; kA
        }
    }
}
