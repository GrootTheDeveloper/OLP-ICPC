#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> adj[100005];

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
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    q.push({1, 1});
    visited[1][1] = true;
    vector<vector<pair<int,int>>> parent(n + 1, vector<pair<int,int>>(m + 1));
//    pair<int,int> parent[1001][1001];

    parent[1][1] = {1, 1};

    while (q.empty() == false) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= m && 
                visited[new_x][new_y] == false && a[new_x][new_y] == '0') {
                    q.push({new_x, new_y});
                    parent[new_x][new_y] = {x, y};
                    visited[new_x][new_y] = true;
                }
        }
    }
    vector<pair<int,int>> ans;
    pair<int,int> cur = {n, m};
    while (cur != parent[cur.first][cur.second]) {
        ans.push_back(cur);
        cur = parent[cur.first][cur.second];
    }
    ans.push_back({1, 1});

    if (visited[n][m] == false) return cout << -1, 0;
    cout << ans.size() - 1 << endl;

}