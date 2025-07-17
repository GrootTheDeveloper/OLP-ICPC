#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Mã hoá (r,c) thành key cho unordered_map / unordered_set
inline ll encode(int r, int c) {
    return (ll(r) << 32) | unsigned(c);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    // 1) Đánh số thứ tự 1..n(n+1)/2 theo đề
    vector<vector<int>> id(n+1, vector<int>(n+1, 0));
    int idx = 1;
    for(int r = n; r >= 1; --r){
        for(int c = 1; c <= n - r + 1; ++c){
            id[r][c] = idx++;
        }
    }

    // 2) Đọc đèn xanh, suy ra đèn đỏ
    vector<bool> isGreen(idx+1, false);
    for(int i = 0; i < k; ++i){
        int x; 
        cin >> x;
        isGreen[x] = true;
    }

    // 3) Gom tất cả các đèn đỏ vào một set để tra cứu O(1)
    unordered_set<ll> redSet;
    redSet.reserve(idx);
    for(int r = 1; r <= n; ++r){
        for(int c = 1; c <= n - r + 1; ++c){
            if (!isGreen[ id[r][c] ]) {
                redSet.insert( encode(r,c) );
            }
        }
    }

    // 4) Xây dựng adjacency chỉ giữa các đèn đỏ
    //    Mỗi nút có tối đa 6 láng giềng trên lưới tam giác
    unordered_map<ll, vector<ll>> adj;
    adj.reserve(redSet.size());
    int drs[6] = {0, 0, 1, -1, 1, -1};
    int dcs[6] = {1, -1, 0, 0, -1, 1};
    for(auto key : redSet){
        int r = int(key >> 32);
        int c = int(key & 0xffffffff);
        auto &nbr = adj[key];
        for(int d = 0; d < 6; ++d){
            int rr = r + drs[d], cc = c + dcs[d];
            ll k2 = encode(rr,cc);
            if (redSet.count(k2)) 
                nbr.push_back(k2);
        }
        // để sau dễ duyệt, sort list láng giềng
        sort(nbr.begin(), nbr.end());
    }

    // 5) Đếm mỗi tam giác đúng 1 lần:
    //    Với mỗi u, chỉ xét các cặp (v,w) trong adj[u] sao cho v<w
    //    và kiểm tra xem v--w có cạnh không
    ll cnt = 0;
    for(auto &it : adj){
        ll u = it.first;
        auto &nbr = it.second;
        int d = nbr.size();
        for(int i = 0; i < d; ++i){
            ll v = nbr[i];
            if (v < u) continue;        // đảm bảo u ≤ v
            for(int j = i+1; j < d; ++j){
                ll w = nbr[j];
                if (w < u) continue;    // đảm bảo u ≤ w
                // kiểm tra v--w
                auto &nv = adj[v];
                // vì nv đã sort, ta có thể binary_search
                if (binary_search(nv.begin(), nv.end(), w)) {
                    // tam giác u-v-w
                    // chỉ đếm u < v < w một lần
                    if (u < v && v < w) 
                        ++cnt;
                }
            }
        }
    }

    cout << cnt << "\n";
    return 0;
}
