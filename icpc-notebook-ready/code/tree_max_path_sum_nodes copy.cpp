struct BIT {
    int n;
    vector<ll> f;
    BIT(int n=0): n(n), f(n+1, 0) {}
    void add(int i, ll v){
        for(; i<=n; i+= i&-i) f[i] += v;
    }
    ll sum(int i){
        ll r=0;
        for(; i>0; i-= i&-i) r += f[i];
        return r;
    }
    // range add [l,r] by v with point query via prefix sums
    void range_add(int l, int r, ll v){
        if(l>r) return;
        add(l, v);
        if(r+1<=n) add(r+1, -v);
    }
};

int main(){
    int n, q;
    if(!(cin >> n >> q)) return 0;
    vector<vector<int>> g(n+1);
    for(int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // Euler tour (iterative) to avoid recursion limits
    vector<int> tin(n+1,0), tout(n+1,0), order; order.reserve(n);
    vector<int> st; st.reserve(2*n);
    vector<int> it(n+1,0), parent(n+1,0);

    int timer = 0;
    st.push_back(1); parent[1]=0;
    while(!st.empty()){
        int u = st.back();
        if(tin[u]==0){
            tin[u] = ++timer;
        }
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

    BIT bit(n);

    while(q--){
        int type; cin >> type;
        if(type==1){
            int u; ll v; cin >> u >> v;
            bit.range_add(tin[u], tout[u], v);
        }else{
            int u; cin >> u;
            cout << bit.sum(tin[u]) << '\n';
        }
    }
    return 0;
}
