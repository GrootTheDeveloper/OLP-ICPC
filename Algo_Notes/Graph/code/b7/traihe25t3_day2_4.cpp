#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int oo = 1e9;
const int MAXN = 405;

vector< pair<int, pair<int, int>> > adj[MAXN]; // adj[u] = {v, {vehicle, weight}}

int code(string &s) {
    if (s == "AIR")   return 1;
    if (s == "SEA")   return 2;
    if (s == "RAIL")  return 3;
    if (s == "TRUCK") return 4;
    return 0;
}

signed main() {
    int num = 1, c; cin >> c;

    map<string, int> StoI;
    map<int, int> changeVehicle;

    for (int i = 1; i <= c; i++) {
        string name;
        int cost;
        cin >> name >> cost;
        StoI[name] = num;
        changeVehicle[num] = cost;
        num++;
    }

    int r; cin >> r;
    for (int i = 1; i <= r; i++) {
        string su, sv, transport;
        int w;
        cin >> su >> sv >> transport >> w;
        int u = StoI[su];
        int v = StoI[sv];
        int vehicle = code(transport);
        adj[u].push_back({v, {vehicle, w}});
        adj[v].push_back({u, {vehicle, w}});
    }

    string s, tstr;
    cin >> s >> tstr;
    int start = StoI[s];
    int target = StoI[tstr];

    vector< vector<int> > dist(c + 1, vector<int>(5, oo));
    dist[start][0] = 0;

    priority_queue< pair<int, pair<int, int>>, vector< pair<int, pair<int, int>> >, greater< pair<int, pair<int, int>> > > pq;
    pq.push({0, {0, start}}); // {cost, {vehicle, node}}

    while (pq.empty() == false) {
        auto top = pq.top(); pq.pop();
        int d = top.first;
        int vehicle = top.second.first;
        int u = top.second.second;

        if (d > dist[u][vehicle]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int next_vehicle = edge.second.first;
            int w = edge.second.second;
            int cost = d + w;

            if (vehicle != 0 && vehicle != next_vehicle) {
                cost += changeVehicle[u];
            }

            if (cost < dist[v][next_vehicle]) {
                dist[v][next_vehicle] = cost;
                pq.push({cost, {next_vehicle, v}});
            }
        }
    }

    int ans = oo;
    for (int i = 0; i <= 4; i++) {
        ans = min(ans, dist[target][i]);
    }

    cout << ans << endl;
}
