#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

vector<vector<bool>> visited(1001, vector<bool>(1001, false));

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


    int cntRoom = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (visited[i][j] == false && a[i][j] != '#') {
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = true;
                cntRoom++;
                while(q.empty() == false) {
                    auto [x, y] = q.front(); q.pop();
                    for (int z = 0; z < 4; z++) {
                        int nx = dx[z] + x;
                        int ny = dy[z] + y;
                        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && visited[nx][ny] == false && a[nx][ny] != '#') {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }
    cout << cntRoom;
    
}