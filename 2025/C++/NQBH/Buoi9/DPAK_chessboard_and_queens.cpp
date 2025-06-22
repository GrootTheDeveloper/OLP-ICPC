#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
int n = 8;
vector<string> s(n);
int ans = 0;

signed main(){

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '*') continue;

            vector<vector<bool>> check(n, vector<bool>(n, false));

            // Đánh dấu hàng và cột
            for (int z = 0; z < n; z++) {
                check[i][z] = true;
                check[z][j] = true;
            }

            // Đánh dấu đường chéo chính
            int x = j, y = i;
            while (x > 0 && y > 0) { x--; y--; }
            while (x < n && y < n) {
                check[y][x] = true;
                x++; y++;
            }

            // Đánh dấu đường chéo phụ
            x = j, y = i;
            while (x < n && y >= 0) {
                check[y][x] = true;
                x++; y--;
            }

            // Đếm số ô chưa bị đánh dấu và không phải '*'
            int cnt = 0;
            for (int bruce = 0; bruce < n; bruce++) {
                for (int sorai = 0; sorai < n; sorai++) {
                    if (check[bruce][sorai] == false && s[bruce][sorai] != '*') {
                        cnt++;
                    }
                }
            }

            ans += cnt;
        }
    }

    cout << ans / 2;
}