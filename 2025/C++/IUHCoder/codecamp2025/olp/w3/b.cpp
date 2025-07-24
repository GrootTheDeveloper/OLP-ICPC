#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n, m; 

void calc(int &x, int &y, char c) {
    if (c == 'S') y++;
    if (c == 'J') y--;
    if (c == 'I') x++;
    if (c == 'Z') x--;
}

int dist(vector<pair<int,int>> a, int x, int y) {

    int total = 0;
    for (int i = 1; i <= n; i++) {
        total += abs(x - a[i].first) + abs(y - a[i].second);
    }
    return total;
}
signed main() {
    cin >> n >> m;
    vector<pair<int,int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    string s; cin >> s;
    s = " " + s;
    int x = 0, y = 0;
    for (int i = 1; i <= m; i++) {
        calc(x, y, s[i]);
        cout << dist(a,x,y) << endl;
    }
}