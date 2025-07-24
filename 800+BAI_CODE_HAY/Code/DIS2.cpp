#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<unordered_set<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v; 
        cin >> u >> v;
        --u; --v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    map<pair<int, int>, int> count_pairs;

    for (int w = 0; w < n; ++w) {
        vector<int> neighbors(adj[w].begin(), adj[w].end());
        int d = neighbors.size();
        for (int i = 0; i < d; ++i) {
            for (int j = i + 1; j < d; ++j) {
                int u = neighbors[i];
                int v = neighbors[j];
                if (u > v) swap(u, v);
                count_pairs[make_pair(u, v)]++;
            }
        }
    }

    long long res = 0;
    for (map<pair<int, int>, int>::iterator it = count_pairs.begin(); it != count_pairs.end(); ++it) {
        int u = it->first.first;
        int v = it->first.second;
        if (adj[u].count(v) == 0) {
            res++;
        }
    }

    cout << res << endl;
    return 0;
}
