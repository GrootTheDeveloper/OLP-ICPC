int main() {
    int q; if (!(cin >> q)) return 0;

    unordered_map<int,int> cnt;
    cnt.reserve(q*2); cnt.max_load_factor(0.7);

    set<int> st;    
    multiset<int> adjXor;  
    long long dupKinds = 0;  

    auto get_pred = [&](int x)->optional<int>{
        auto it = st.lower_bound(x);
        if (it == st.begin()) return {};
        --it; return *it;
    };
    auto get_succ = [&](int x)->optional<int>{
        auto it = st.upper_bound(x);
        if (it == st.end()) return {};
        return *it;
    };
    auto erase_one_adj = [&](int val){
        auto it = adjXor.find(val);
        if (it != adjXor.end()) adjXor.erase(it);
    };

    auto insert_value = [&](int x){
        int c = cnt[x]++;
        if (c == 1) { 
            ++dupKinds;
            return;
        }
        if (c >= 2) return; 
        auto p = get_pred(x);
        auto s = get_succ(x);
        if (p && s) erase_one_adj((*p) ^ (*s));
        if (p) adjXor.insert((*p) ^ x);
        if (s) adjXor.insert(x ^ (*s));
        st.insert(x);
    };

    auto erase_value = [&](int x){
        int c = cnt[x];
        if (c == 2) {
            --dupKinds;
            cnt[x] = 1;
            return;
        }
        if (c > 2) {
            cnt[x] = c - 1;
            return;
        }
        cnt.erase(x);
        auto p = get_pred(x);
        auto s = get_succ(x);
        if (p) erase_one_adj((*p) ^ x);
        if (s) erase_one_adj(x ^ (*s));
        if (p && s) adjXor.insert((*p) ^ (*s));
        st.erase(x);
    };

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x;
            insert_value(x);
        } else if (t == 2) {
            int x; cin >> x;
            erase_value(x);
        } else {
            if (dupKinds > 0) {
                cout << 0 << '\n';
            } else {
                cout << *adjXor.begin() << '\n';
            }
        }
    }
    return 0;
}
