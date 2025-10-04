#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int N = 2000;
vector<bool> prime(N + 1, true);

int main() {
    prime[0] = prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= N; j+=i) {
                prime[j] = false;
            }
        }
    }

    int n, k; cin >> n >> k;
    vector<vector<int>> f(n  + 1, vector<int>(k + 1, 0));

    //f[i][j] : tong so luong mang co do dai i va ket thuc tai gia tri j

    for (int i = 0; i <= k; i++) {
        f[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int x = 0; x <= k; x++) {
                (f[i][j] = f[i][j] + (prime[x + j] ? f[i - 1][x] : 0)) %= mod;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= k; i++) (ans += f[n][i]) %= mod;

    cout << ans;

}