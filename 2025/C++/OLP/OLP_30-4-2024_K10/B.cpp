#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> deg(n+1, 0);
    for (int i = 1; i <= n; i++){
        deg[i] = adj[i].size();
    }
    
    // Tách thành phần liên thông
    vector<int> compId(n+1, -1);
    vector<int> compSize; // compSize[id] là kích thước của thành phần id
    int compCount = 0;
    vector<bool> visited(n+1, false);
    
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            int size = 0;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            compId[i] = compCount;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                size++;
                for(auto nxt : adj[cur]){
                    if(!visited[nxt]){
                        visited[nxt] = true;
                        compId[nxt] = compCount;
                        q.push(nxt);
                    }
                }
            }
            compSize.push_back(size);
            compCount++;
        }
    }
    
    // ánh xạ từ deg sang tập hợp các thành phần liên thông có chứa ít nhất 1 đỉnh có deg đó
    unordered_map<int, set<int>> tempMap;
    for (int i = 1; i <= n; i++){
        tempMap[deg[i]].insert(compId[i]);
    }
    
    unordered_map<int, vector<int>> degToComps;
    for (auto &entry : tempMap) {
        int d = entry.first;
        vector<int> comps(entry.second.begin(), entry.second.end());
        sort(comps.begin(), comps.end(), [&](int a, int b){
            return compSize[a] > compSize[b];
        });
        degToComps[d] = comps;
    }
    
    int ans = 0;
    for (auto &p : degToComps) {
        int sum = 0;
        int cnt = 0;
        for (int comp : p.second) {
            if (cnt < k) {
                sum += compSize[comp];
                cnt++;
            } else break;
        }
        ans = max(ans, sum);
    }
    
    cout << ans;
    return 0;
}
