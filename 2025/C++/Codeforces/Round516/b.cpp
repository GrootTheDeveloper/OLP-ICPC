#include <bits/stdc++.h>
#define int long long
const int oo = 1e18;
using namespace std;


signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m;
    cin >> r >> c;
    cin >> BruceTheLuckyPlumber >> TheNaughtyProfessorV;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            visited[i][j] = {oo,oo};
            cin >> a[i][j];
        }
    }
    BruceTheLuckyPlumber = min(BruceTheLuckyPlumber, n*m);
    TheNaughtyProfessorV = min(TheNaughtyProfessorV, m*m);
    queue<pair<pair<int,int>,pair<int,int>>> q;
    visited[r][c] = {BruceTheLuckyPlumber, TheNaughtyProfessorV};
    q.push({{r, c}, {BruceTheLuckyPlumber, TheNaughtyProfessorV}});
    while (q.empty() == false) {
        auto [pt, lt] = q.front();
        auto [x, y] = pt;
        // cout << x << ' ' << y << endl;
        auto [cl, cr] = lt;
        q.pop();

        if (cl >= 1)  {
            if (check(x, y, x, y - 1)) {
                if (visited[x][y - 1] == pair<int,int> {oo, oo}) {
                    visited[x][y - 1] = {cl - 1, cr};
                }
                else {
                    visited[x][y - 1].first = max(visited[x][y - 1].first, cl - 1);
                    visited[x][y - 1].second = max(visited[x][y - 1].second, cr);
                }   
                q.push({{x, y - 1}, {cl - 1, cr}});
            }
        }
        if (cr >= 1) {
            if (check(x, y, x, y + 1)) {
                if (visited[x][y + 1] == pair<int,int> {oo, oo}) {
                    visited[x][y + 1] = {cl, cr - 1};
                }
                else {
                    visited[x][y + 1].first = max(visited[x][y + 1].first, cl);
                    visited[x][y + 1].second = max(visited[x][y + 1].second, cr - 1);
                }
                q.push({{x, y + 1}, {cl, cr - 1}});
            }
        }
        if (check(x,y, x + 1, y)) {
            if (visited[x + 1][y] == pair<int,int> {oo, oo}) {
                visited[x + 1][y] = {cl, cr};
            }
            else {
                visited[x + 1][y].first = max(visited[x + 1][y].first, cl);
                visited[x + 1][y].second = max(visited[x + 1][y].second, cr);
            }
            q.push({{x + 1, y}, {cl, cr}});
        }
        if (check(x, y, x - 1, y)) {
            if (visited[x - 1][y] == pair<int,int> {oo, oo}) {
                visited[x - 1][y] = {cl, cr};
            }
            else {
                visited[x - 1][y].first = max(visited[x - 1][y].first, cl);
                visited[x - 1][y].second = max(visited[x - 1][y].second, cr);
            }
            q.push({{x - 1, y}, {cl, cr}});
        }

    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (visited[i][j] != pair<int,int>{oo, oo}) {
                ans++;
            }
        }
    }
    cout << ans;


}