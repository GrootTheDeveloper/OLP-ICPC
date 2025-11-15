using ll = long long;
const ll INF = LLONG_MAX / 4;
int main() {
    ll n; ll A, B, C;
    cin >> n >> A >> B >> C;
    ll N = n - 1;
    ll m = min({A, B, C});
    vector<ll> dist(m, INF);
    dist[0] = 0;

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, 0});

    auto relax = [&](int r, ll x) {
        ll newt = dist[r] + x;
        int nr = newt % m;
        if (newt < dist[nr]) {
            dist[nr] = newt;
            pq.push({newt, nr});
        }
    };

    while (!pq.empty()) {
        auto [cd, r] = pq.top(); 
        pq.pop();
        if (cd > dist[r]) continue;
        relax(r, A);
        relax(r, B);
        relax(r, C);
    }
    ll ans = 0;
    for (int r = 0; r < m; r++) if (dist[r] <= N) ans += (N - dist[r]) / m + 1;
    cout << ans << "\n";
    return 0;
}
