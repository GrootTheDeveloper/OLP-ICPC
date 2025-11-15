const int MAXN = 100000;
int n, q;
vector<int> g[MAXN+1];

int LOG;
int up[20][MAXN+1];
int depth_[MAXN+1];
int sz[MAXN+1];

void dfs(int u, int p){
    up[0][u] = (p ? p : u);
    depth_[u] = p ? depth_[p] + 1 : 0;
    sz[u] = 1;
    for (int v : g[u]) if (v != p){
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int lift(int u, int k){
    for (int i = 0; i < LOG; ++i)
        if (k & (1<<i)) u = up[i][u];
    return u;
}

int lca(int u, int v){
    if (depth_[u] < depth_[v]) swap(u, v);
    u = lift(u, depth_[u] - depth_[v]);
    if (u == v) return u;
    for (int i = LOG-1; i >= 0; --i){
        if (up[i][u] != up[i][v]){
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][u];
}

int dist(int u, int v){
    int w = lca(u, v);
    return depth_[u] + depth_[v] - 2*depth_[w];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if(!(cin >> n >> q)) return 0;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    LOG = 1;
    while ((1<<LOG) <= n) ++LOG;

    dfs(1, 0);
    for (int k = 1; k < LOG; ++k){
        for (int v = 1; v <= n; ++v){
            up[k][v] = up[k-1][ up[k-1][v] ];
        }
    }

    while(q--){
        int u, v; cin >> u >> v;
        if (u == v){
            cout << n << '\n';
            continue;
        }
        int d = dist(u, v);
        if (d & 1){
            cout << 0 << '\n';
            continue;
        }

        int w = lca(u, v);
        int du = depth_[u] - depth_[w];
        int dv = depth_[v] - depth_[w];
        int half = d / 2;

        if (du == dv){
            // midpoint is w
            // a: child of w towards u; b: child of w towards v
            int a = lift(u, du - 1);
            int b = lift(v, dv - 1);
            long long ans = (long long)n - sz[a] - sz[b];
            cout << ans << '\n';
        } else {
            // midpoint m lies on the deeper side
            if (du < dv) {
                // make u the deeper one
                swap(u, v);
                swap(du, dv);
            }
            // u deeper: go up half steps to reach m
            int m = lift(u, half);
            // child c from m towards u: go up (half - 1) from u
            int c = lift(u, half - 1);
            long long ans = (long long)sz[m] - sz[c];
            cout << ans << '\n';
        }
    }
    return 0;
}
