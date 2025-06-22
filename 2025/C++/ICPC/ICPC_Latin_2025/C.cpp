#include <bits/stdc++.h>
using namespace std;
#define int long long

template<typename T> void __print(const T &x) { cerr << x; }

template<typename T, typename V> void __print(const pair<T, V> &x) { cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}'; }

// Print for 2D array (N rows, M cols)
template<typename T, size_t N, size_t M> void __print(const T (&x)[N][M]) { cerr << "\n"; for (size_t i = 0; i < N; ++i) { cerr << "["; for (size_t j = 0; j < M; ++j) { cerr << x[i][j]; if (j + 1 < M) cerr << " "; } cerr << "],\n"; } }

template<typename T>
void __print(const vector<vector<T>> &x) { cerr << "\n"; for (auto &row : x) { cerr << "{"; for (size_t j = 0; j < row.size(); ++j) {cerr << row[j]; if (j + 1 < row.size()) cerr << " "; } cerr << "},\n"; } }

template<typename T, size_t N> void __print(const T (&x)[N]) { cerr << "{"; bool first = true; for (size_t i = 0; i < N; ++i) { if (!first) cerr << ", "; __print(x[i]); first = false; } cerr << "}"; }

template<typename T> void __print(const vector<T> &x) { cerr << '['; bool first = true; for (const auto &i : x) { if (!first) cerr << ", "; __print(i); first = false; } cerr << ']'; }

template<typename T> void __print(const deque<T> &x) { cerr << '['; bool first = true; for (const auto &i : x) { if (!first) cerr << ", "; __print(i); first = false; } cerr << ']'; }

template<typename T> void __print(const list<T> &x) { cerr << '['; bool first = true; for (const auto &i : x) { if (!first) cerr << ", "; __print(i); first = false; } cerr << ']'; }

template<typename T> void __print(const set<T> &x) { cerr << '{'; bool first = true; for (const auto &i : x) { if (!first) cerr << ", "; __print(i); first = false; } cerr << '}'; }

template<typename T> void __print(const multiset<T> &x) { cerr << '{'; bool first = true; for (const auto &i : x) { if (!first) cerr << ", "; __print(i); first = false; } cerr << '}'; }

template<typename T> void __print(const unordered_set<T> &x) { cerr << '{'; bool first = true; for (const auto &i : x) { if (!first) cerr << ", "; __print(i); first = false; } cerr << '}'; }

template<typename T, typename V> void __print(const map<T, V> &x) { cerr << '{'; bool first = true; for (const auto &i : x) { if (!first) cerr << ", "; __print(i); first = false; } cerr << '}'; }

template<typename T, typename V> void __print(const unordered_map<T, V> &x) { cerr << '{'; bool first = true; for (const auto &i : x) { if (!first) cerr << ", "; __print(i); first = false; } cerr << '}'; }

template<typename T> void __print(queue<T> x) { cerr << "<queue:["; bool first = true; while (!x.empty()) { if (!first) cerr << ", "; __print(x.front()); x.pop(); first = false; } cerr << "]>"; }

template<typename T> void __print(stack<T> x) { cerr << "<stack:["; vector<T> v; while (!x.empty()) { v.push_back(x.top()); x.pop(); } reverse(v.begin(), v.end()); bool first = true; for (auto &i : v) { if (!first) cerr << ", "; __print(i); first = false; } cerr << "]>"; }

template<typename T> void __print(priority_queue<T> x) { cerr << "<pq:["; vector<T> v; while (!x.empty()) { v.push_back(x.top()); x.pop(); } bool first = true; for (auto &i : v) { if (!first) cerr << ", "; __print(i); first = false; } cerr << "]>"; }

template<typename T, typename Cmp> void __print(priority_queue<T, vector<T>, Cmp> x) { cerr << "<pq:["; vector<T> v; while (!x.empty()) { v.push_back(x.top()); x.pop(); } sort(v.begin(), v.end()); bool first = true; for (auto &i : v) { if (!first) cerr << ", "; __print(i); first = false; } cerr << "]>"; }

void _print() { cerr << endl; }
template<typename T, typename... V> void _print(const T &t, const V&... v) { __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }

#ifndef ONLINE_JUDGE
#define debug(...) cerr  << "line: " << __LINE__ << ", function: " << __func__ << ", [" << #__VA_ARGS__ << "] = ", _print(__VA_ARGS__), cerr << endl
#else
#define debug(...)
#endif

signed main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        /* n - 1 cạnh
        
        trừ đỉnh gốc, các đỉnh phải nối từ 1 --> n - 2 cạnh = 1 để tổng n - 2 cạnh = m - (n - 2)
        gốc - 1
        */
        if (n > m) {
            cout << -1 << endl;
            continue;
        }
        if (n == 1) {
            if (m == 1) {
                cout << n;
            }
            else {
                cout << -1;
            }
            cout << endl;
            continue;
        }
        int root = m - (n - 2) - 1;
        if (root <= 0 || root > n) {
        cout << -1 << endl;
        }
        else {
            vector<bool> node(n + 1, false);
            node[root] = true;
            cout << root << endl;

            int prev = root, cur = 1;
            if (prev == 1) cur = 2;
            node[cur] = true;
            cout << prev << " " << cur << endl;
            prev = cur;
            for (int i = 2; i <= n; i++) {
                if (node[i]) continue;
                cout << prev << " " << i << endl;
                prev = cur;
            }
        }
    }
}
