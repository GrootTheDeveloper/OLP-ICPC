#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

signed main() {
    int n; cin >> n;
    string s; cin >> s;
    int len = s.size();
    s = " " + s;
    vector<vector<char>> a(n + 1, vector<char>(n + 1, '-'));

    pair<int,int> cur = {n / 2 + 1, n / 2 + 1};
    int num = 1;
    a[cur.first][cur.second] = s[num++];
    int step = 1;
    /*
    sau khi re 2 lan -> step++
    */
    int dir = 0;
    while (num <= len) {
        for (int re = 0; re < 2 && num <= len; re++) {
            for (int i = 0; i < step && num <= len; i++) {
                cur.first += dx[dir];
                cur.second += dy[dir];
                a[cur.first][cur.second] = s[num++];
            }
            dir = (dir + 1) % 4;
        }
        step++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != '-') cout << a[i][j];
        }
    }
}