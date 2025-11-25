#include <bits/stdc++.h>
#define int long long

using namespace std;
const int MAXN = 2e5 + 5;
const int oo = 1e18 + 7;

using Node = tuple<int,int,int,int>; // (d, x,y,z)
// đường đi từ (1,1,1) đến (x, y, z) có chi phí là d

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0 , 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

signed main() {
    int n; cin >> n ;
    int a[101][101][101];
    int dist[101][101][101];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                cin >> a[i][j][k];
                dist[i][j][k] = oo;
            } 
        }
    }

    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[1][1][1] = 0;
    pq.push({0, 1, 1, 1});
    while (pq.empty() == false) {
        auto [d, x, y, z] = pq.top();
        pq.pop();

        if (d != dist[x][y][z]) continue;

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && nz >= 1 && nz <= n) {
                
                if (dist[nx][ny][nz] > d + a[nx][ny][nz]) {
                    dist[nx][ny][nz] = d + a[nx][ny][nz];
                    pq.push({dist[nx][ny][nz], nx, ny, nz});
                }
            }
        }
    }
    cout << dist[n][n][n];
}