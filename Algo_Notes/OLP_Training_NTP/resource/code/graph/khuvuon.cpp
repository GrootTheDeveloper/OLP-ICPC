#include <bits/stdc++.h>
#define int long long

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

signed main() {
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));

    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (visited[i][j] == true || a[i][j] == '#') continue;

            queue<pair<int,int>> q;
            q.push({i, j});
            visited[i][j] = true;

            int soQua = 0;
            if (a[i][j] == 'x') soQua++;

            while (q.empty() == false) {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int new_x = x + dx[k];
                    int new_y = y + dy[k];
                    if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= m && 
                        visited[new_x][new_y] == false && a[new_x][new_y] != '#') {
                            q.push({new_x, new_y});
                            visited[new_x][new_y] = true;
                            if (a[new_x][new_y] == 'x') {
                                soQua++;
                            }
                        }
                }
            }
            if (soQua != 0) ans.push_back(soQua);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans) cout << i << " ";

}