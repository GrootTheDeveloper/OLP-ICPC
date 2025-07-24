#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define iii pair<int, ii>
#define fi first
#define se second

vector<vector<char>> a;
vector<vector<int>> cx, cy;
vector<vector<bool>> mark;
int dx[2] = {1,0}, dy[2] = {0,1};
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int m, n; cin >> m >> n;
    a.assign(m + 5, vector<char> (n + 5, '#'));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    mark.resize(m + 3, vector<bool>(n + 3, false));
    cx.resize(m + 3, vector<int> (n + 3, 0));
    cy.resize(m + 3, vector<int> (n + 3, 0));
    deque <iii> dq;
    mark[1][1] = true;
    dq.push_front({a[1][1] - 'a',{1,1}});
    while (!dq.empty())
    {
        iii top = dq.front(); dq.pop_front();
        int x = top.se.fi, y = top.se.se, w = top.fi;
        for (int i = 0; i < 2; i++)
        {
            int nx = dx[i] + x, ny = dy[i] + y;
            if (mark[nx][ny] || a[nx][ny] == '#') continue;
            int nw = a[nx][ny] - 'a';
            cx
        }

    }


    vector <char> ans;
    while (m != 1 || n != 1)
    {
        ans.push_back(a[m][n]);
        int t1 = m, t2 = n;
        m = m - cx[t1][t2];
        n = n - cy[t1][t2];
    }
    ans.push_back(a[1][1]);
    reverse(ans.begin(), ans.end());
    for (char c : ans) cout << c;
}












