#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> a;
vector<vector<bool>> check;
vector<pair<int,int>> monsters;
pair<int,int> A;
pair<int,int> parent[1005][1005];
vector<pair<int,int>> target;

vector<vector<int>> minMonstersTime;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void monsterBFS() {
    queue<pair<pair<int,int>,int>> q;
    vector<vector<bool>> monsterCheck(n + 1, vector<bool>(m + 1, false));

    for (auto monster : monsters) {
        int start_x = monster.first;
        int start_y = monster.second;
        q.push({{start_x, start_y}, 0});
        monsterCheck[start_x][start_y] = true;
        minMonstersTime[start_x][start_y] = 0;
    }

    while(!q.empty()) {
        auto [point, time] = q.front();
        auto [x,y] = point;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= m && 
                a[new_x][new_y] != '#' && monsterCheck[new_x][new_y] == false) {
                q.push({{new_x, new_y}, time + 1});
                monsterCheck[new_x][new_y] = true;
                minMonstersTime[new_x][new_y] = time + 1;
            }
        }
    }
}

bool bfsA() {
    queue<pair<pair<int,int>,int>> q;
    q.push({A, 0});
    check[A.first][A.second] = true;

    while(q.empty() == false) {
        auto [point, time] = q.front();
        auto [x,y] = point;
        q.pop();

        
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            
            if (new_x >= 1 && new_x <= n && new_y >= 1 && new_y <= m && 
                a[new_x][new_y] != '#' && check[new_x][new_y] == false) {
                if (time + 1 < minMonstersTime[new_x][new_y]) {
                    q.push({{new_x, new_y}, time + 1});
                    parent[new_x][new_y] = {x,y};
                    check[new_x][new_y] = true;
                }
            }
        }

        for (auto t : target) {
            auto [x,y] = t;
            if (check[x][y]) {
                
                vector<pair<int,int>> path;
                pair<int,int> current = {x,y};
                while (current != A) {
                    path.push_back(current);
                    current = parent[current.first][current.second];
                }
                path.push_back(A);
                reverse(path.begin(), path.end());
                vector<char> real_path;

                for (int i = 1; i < path.size(); i++) {
                    auto [x,y] = path[i];
                    auto [prev_x, prev_y] = path[i - 1];
                    if (prev_y + 1 == y) {
                        real_path.push_back('R');
                    }
                    else if (prev_y - 1 == y) {
                        real_path.push_back('L');
                    }
                    else if (prev_x + 1 == x) {
                        real_path.push_back('D');
                    }
                    else {
                        real_path.push_back('U');
                    }
                }
                cout << "YES" << endl << real_path.size() << endl;
                for (auto r : real_path) {
                    cout << r;
                }
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    a.resize(n + 1, vector<char>(m + 1));
    minMonstersTime.resize(n + 1, vector<int>(m + 1, INT_MAX));
    check.resize(n + 1, vector<bool>(m + 1, false));    

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                A = {i,j};
            }
            else if (a[i][j] == 'M') {
                monsters.push_back({i,j});
            }
            if (i == 1 || i == n || j == 1 || j == m) {
                if (a[i][j] == '.') {
                    target.push_back({i,j});
                }
                if (a[i][j] == 'A') {
                    cout << "YES\n0";
                    return 0;
                }
            }
        }
    }
    monsterBFS();
    bool ans = bfsA();
    if (!ans) {
        cout << "NO";
    }
}
