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
        int l[3], r[3];
        for (int i = 0; i < 3; i++) {
            cin >> l[i] >> r[i];
        }

        bool ok = false;
        for (int a = 0; a < 3; a++) {
            for (int b = 0; b < 3; b++) {
                for (int c = 0; c < 3; c++) {
                    if (a == b || b == c || a == c) continue;

                    int l1 = l[a], r1 = r[a];
                    int l2 = l[b], r2 = r[b];
                    int l3 = l[c], r3 = r[c];

                    int area = l1 * r1 + l2 * r2 + l3 * r3;
                    int S = sqrt(area);
                    if (S * S != area) continue;

                    if (max({l1, l2, l3}) > S || max({r1, r2, r3}) > S) continue;

                    if (r1 == r2 && r2 == r3 && l1 + l2 + l3 == S && r1 == S) {
                        ok = true;
                    }

                    if (l1 == l2 && l2 == l3 && r1 + r2 + r3 == S && l1 == S) {
                        ok = true;
                    }

                    if (l1 == S && r1 < S && r2 == r3 && r1 + r2 == S && l2 + l3 == S) {
                        ok = true;
                    }

                    if (r1 == S && l1 < S && l2 == l3 && l1 + l2 == S && r2 + r3 == S) {
                        ok = true;
                    }
                }
            }
        }
    if (ok) cout << "YES"; else cout << "NO";
    cout << endl;
    }
}
