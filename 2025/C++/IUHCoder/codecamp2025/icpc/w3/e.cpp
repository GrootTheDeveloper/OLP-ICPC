#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int oo = 1e9;

int code(string &s) {
    if (s == "AIR")   return 1;
    if (s == "SEA")   return 2;
    if (s == "RAIL")  return 3;
    if (s == "TRUCK") return 4;
    return 0;
}

vector<pair<int, pair<int, int>>> adj[401];
// (v, {mode, w})

signed main() {
    int c; cin >> c;
    map<string, int> StoI;
    map<int, int> changeVehicle; 
    int num = 1;

    for (int i = 1; i <= c; i++) {
        string name; int cost;
        cin >> name >> cost;
        StoI[name] = num;
        changeVehicle[num++] = cost;
    }
    int r; cin >> r;
    for (int R = 1; R <= r; R++) {
        string u, v, t; int w;
        cin >> u >> v >> t >> w;
        int mu = StoI[u];
        int mv = StoI[v];
        int mode = code(t);
        adj[mu].push_back({mv,{mode, w}});
        adj[mv].push_back({mu,{mode, w}});
    }

    string s, tstr;
    cin >> s >> tstr;
    int start  = StoI[s];
    int target = StoI[tstr];

    // dist[u][m]: chi phí nhỏ nhất để đến u khi đang dùng phương tiện m (0 = chưa dùng)
    vector<vector<int>> dist(c + 1, vector<int>(5, oo));
    dist[start][0] = 0;

    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
    // {cost, {currentMode, u}}
    pq.push({0, {0, start}});

    while (!pq.empty()) {
        auto [d, xu] = pq.top(); pq.pop();
        auto [vehicle, u] = xu;
        if (d > dist[u][vehicle]) continue;
        for (auto &e : adj[u]) {
            int v = e.first;
            int v_vehicle = e.second.first;
            int w = e.second.second;
            int cost = d + w;
            if (vehicle != 0 && vehicle != v_vehicle) {
                cost += changeVehicle[u];
            }
            if (cost < dist[v][v_vehicle]) {
                dist[v][v_vehicle] = cost;
                pq.push({cost, {v_vehicle, v}});
            }
        }
    }

    int ans = oo;
    for (int i = 0; i < 5; i++) {
        ans = min(ans, dist[target][i]);
    }

    cout << ans << endl;
}
