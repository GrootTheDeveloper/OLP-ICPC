struct SegTree {
    int n;
    vector<ll> lazy;
    SegTree(int n=0): n(n), lazy(4*n+4, 0) {}
    void range_add(int p, int L, int R, int i, int j, ll v) {
        if (j < L || R < i) return;
        if (i <= L && R <= j) { lazy[p] += v; return; }
        int M = (L + R) >> 1;
        range_add(p<<1, L, M, i, j, v);
        range_add(p<<1|1, M+1, R, i, j, v);
    }
    void range_add(int l, int r, ll v){ if(l<=r) range_add(1,1,n,l,r,v); }
    ll point_query(int p, int L, int R, int idx) {
        if (L == R) return lazy[p];
        int M = (L + R) >> 1;
        if (idx <= M) return lazy[p] + point_query(p<<1, L, M, idx);
        else          return lazy[p] + point_query(p<<1|1, M+1, R, idx);
    }
    ll point_query(int idx){ return point_query(1,1,n,idx); }
};

int main(){
    int n, q; if(!(cin >> n >> q)) return 0;
    vector<vector<int>> g(n+1);
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // Euler tour: tin[u]..tout[u] là đoạn subtree(u)
    vector<int> tin(n+1,0), tout(n+1,0), parent(n+1,0), it(n+1,0), order; order.reserve(n);
    vector<int> st; st.reserve(2*n);
    int timer = 0;
    st.push_back(1); parent[1]=0;
    while(!st.empty()){
        int u = st.back();
        if(tin[u]==0) tin[u] = ++timer;
        if(it[u] < (int)g[u].size()){
            int v = g[u][it[u]++];
            if(v==parent[u]) continue;
            parent[v]=u;
            st.push_back(v);
        }else{
            tout[u] = timer;
            st.pop_back();
        }
    }

    SegTree stree(n);

    while(q--){
        int type; cin >> type;
        if(type==1){
            int u; ll v; cin >> u >> v;
            stree.range_add(tin[u], tout[u], v);
        }else{
            int u; cin >> u;
            cout << stree.point_query(tin[u]) << '\n';
        }
    }
    return 0;
}
