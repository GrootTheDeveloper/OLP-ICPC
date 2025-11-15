#include <bits/stdc++.h>
#define int long long
using namespace std;

struct point { 
    int x, y; 
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool gotBlack(int n, vector<vector<char>>& a) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == '#') return true;
        }
    }
    return false;
}

point firstBlack(int n, vector<vector<char>>& a) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == '#') return {i, j};
        }
    }
    return {-1, -1};
}

bool isConnected(int n, vector<vector<char>>& a, point start) {
    if (start.x == -1) return false;
    vector<vector<bool>> visited(n + 1, vector<bool>(n + 1, false));
    queue<point> q;
    q.push(start);
    visited[start.x][start.y] = true;

    while (q.empty() == false) {
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
            if (!visited[nx][ny] && a[nx][ny] == '#') {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == '#' && !visited[i][j]) return false;
        }
    }
    return true;
}

bool hasThreeConsecutive(int n, vector<vector<char>>& a) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j + 2 <= n; j++) {
            if (a[i][j] == '#' && a[i][j+1] == '#' && a[i][j+2] == '#') return true;
        }
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i + 2 <= n; i++) {
            if (a[i][j] == '#' && a[i+1][j] == '#' && a[i+2][j] == '#') return true;
        }
    }
    return false;
}

bool check_now(int n, vector<vector<char>>& a) {
    if (!gotBlack(n, a)) return false; 
    if (hasThreeConsecutive(n, a)) return false;
    point st = firstBlack(n, a);
    if (!isConnected(n, a, st)) return false;
    return true;
}

vector<vector<int>> getBlackComponent(int n, vector<vector<char>> &a, int &comps) {
    vector<vector<int>> comp(n + 1, vector<int>(n + 1, 0));
    comps = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == '#' && comp[i][j] == 0) {
                comp[i][j] = ++comps;
                queue<point> q; q.push((point){i,j});
                while (q.empty() == false) {
                    auto [x, y] = q.front(); q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
                        if (comp[nx][ny] == 0 && a[nx][ny] == '#') {
                            comp[nx][ny] = comps;
                            q.push((point){nx, ny});
                        }
                    }
                }
            }
        }
    }
    return comp;
}

bool isBlack(int n, int i, int j, vector<vector<char>> &a, int pi, int pj) {
    if (pi == i && pj == j) return true;
    if (i >= 1 && i <= n && j >= 1 && j <= n) return a[i][j] == '#';
    return false; 
} 

bool safe(int n, int i, int j, vector<vector<char>> &a) {
    if (isBlack(n,i, j, a, i, j) && isBlack(n, i, j - 1, a, i, j) && isBlack(n, i, j - 2, a, i, j)) return false;
    if (isBlack(n,i, j - 1, a, i, j) && isBlack(n, i, j, a, i, j) && isBlack(n, i, j + 1, a, i, j)) return false;
    if (isBlack(n,i, j, a, i, j) && isBlack(n, i, j + 1, a, i, j) && isBlack(n, i, j + 2, a, i, j)) return false;

    if (isBlack(n,i, j, a, i, j) && isBlack(n, i - 1, j, a, i, j) && isBlack(n, i - 2, j, a, i, j)) return false;
    if (isBlack(n,i - 1, j, a, i, j) && isBlack(n, i, j, a, i, j) && isBlack(n, i + 1, j, a, i, j)) return false;
    if (isBlack(n,i, j, a, i, j) && isBlack(n, i + 1, j, a, i, j) && isBlack(n, i + 2, j, a, i, j)) return false;
    return true;
}

bool canMergeFromSeed(int n, const vector<vector<char>>& a0, const vector<vector<int>>& compId, const vector<vector<point>>& compOfCells, int comps, int seed) {
    vector<vector<char>> chosen = a0;
    vector<int> merged(comps + 1, 0);
    merged[seed] = 1;
    int mergeCount = 1;

    queue<point> q;
    for (auto &c : compOfCells[seed]) q.push(c);

    while (!q.empty() && mergeCount < comps) {
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > n) continue;

            if (chosen[nx][ny] == '#') {
                int cid = compId[nx][ny]; 
                if (cid != 0 && merged[cid] == 0) {
                    merged[cid] = 1;
                    ++mergeCount;
                    for (auto &c : compOfCells[cid]) q.push(c);
                }
            } else {
                if (safe(n, nx, ny, chosen)) {
                    chosen[nx][ny] = '#';
                    q.push({nx, ny});

                    if (a0[nx][ny] == '#') {
                        int cid0 = compId[nx][ny];
                        if (cid0 != 0 && merged[cid0] == 0) {
                            merged[cid0] = 1;
                            ++mergeCount;
                            for (auto &c : compOfCells[cid0]) q.push(c);
                        }
                    }
                    for (int kk = 0; kk < 4; kk++) {
                        int px = nx + dx[kk], py = ny + dy[kk];
                        if (px < 1 || px > n || py < 1 || py > n) continue;
                        if (a0[px][py] == '#') {
                            int cid = compId[px][py];
                            if (cid != 0 && merged[cid] == 0) {
                                merged[cid] = 1;
                                ++mergeCount;
                                for (auto &c : compOfCells[cid]) q.push(c);
                            }
                        }
                    }
                }
            }
        }
    }
    return (mergeCount == comps);
}

signed main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        vector<vector<char>> a(n + 1, vector<char>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }

        if (hasThreeConsecutive(n, a)) {
             cout << "NO" << endl;
            continue;
        }
        if (gotBlack(n , a) == false) {
            cout << "YES" << endl;
            continue;
        }

        int comps = 0;
        auto compId = getBlackComponent(n, a, comps);
        if (comps == 1) {
            cout << "YES" << endl;
            continue;
        }

        vector<vector<point>> compOfCells(comps + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] == '#') {
                    compOfCells[compId[i][j]].push_back((point){i, j});
                }
            }
        }
        bool ok = false;
        for (int seed = 1; seed <= comps && !ok; seed++)
            ok = canMergeFromSeed(n, a, compId, compOfCells, comps, seed);

        cout << (ok ? "YES" : "NO") << endl;
    }
}