#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

vector<int> adj[100005];
vector<bool> visited(100005, false);
vector<int> st;

void dfs(int u) {
    visited[u] = true;
    for (auto v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
    st.push_back(u);
}

signed main() {
    int n = 8, m = 2;
    vector<int> group = {-1, -1, 1, 0, 0, 1, 0 , -1};
    vector<vector<int>> beforeItems = {{}, {6}, {5}, {6}, {3, 6}, {}, {}, {}};

    vector<vector<int>> EgdeInGroup(n);

    vector<int> noGroup;
    for (int i = 0; i < n; i++) {
        if (group[i] == -1) ;
        else EgdeInGroup[group[i]].push_back(i);
    }

    for (int i = 0 ; i < n; i++) {
        for (auto v : beforeItems[i]) {
            adj[v].push_back(i);
        }
    }
    for (int i = 0; i < m; i++) {
        for (auto u : EgdeInGroup[i]) {
            dfs(u);
        }
        reverse(st.begin(), st.end());
        for (auto s : st) {
            cout << s << " ";
        }
        st.clear();
    }
    return 0;
}
