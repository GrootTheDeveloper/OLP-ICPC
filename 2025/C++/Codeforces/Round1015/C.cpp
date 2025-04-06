#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        map<pair<int, int>, vector<int>> groups;
        for (int i = 0; i < n; i++) groups[{a[i], b[i]}].push_back(i);
        

        bool check = true;
        vector<pair<int, int>> pairings;  
        vector<int> selfSym;

        for (auto& entry : groups) {
            auto key = entry.first;
            if (key.first == key.second) {
                for (auto idx : entry.second)
                    selfSym.push_back(idx);
            }
            else {
                pair<int, int> revKey = { key.second, key.first };
                if (key < revKey) {
                    if (groups.find(revKey) == groups.end()) {
                        check = false;
                        break;
                    }
                    auto& vec1 = entry.second;
                    auto& vec2 = groups[revKey];
                    if (vec1.size() != vec2.size()) {
                        check = false;
                        break;
                    }
                    for (int i = 0; i < vec1.size(); i++) {
                        pairings.push_back({ vec1[i], vec2[i] });
                    }
                }
            }
        }
        if (n % 2 == 0) {
            if (!selfSym.empty()) {
                check = false;
            }
        }
        else {
            if (selfSym.size() != 1) {
                check = false;
            }
        }

        int pairsNeeded = n / 2;
        if (pairings.size() != pairsNeeded) {
            check = false;
        }

        if (!check) {
            cout << -1 << endl;
            continue;
        }

        vector<int> R(n, -1);
        int L = 0, Rpos = n - 1;
        for (auto& pr : pairings) {
            R[L] = pr.first;
            R[Rpos] = pr.second;
            L++;
            Rpos--;
        }
        if (n % 2 == 1) {
            R[n / 2] = selfSym[0];
        }

        vector<int> P(n);
        for (int i = 0; i < n; i++) {
            P[i] = i;
        }
        vector<bool> visited(n, false);
        vector<pair<int, int>> ops;

        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[P[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            if (P[i] != R[i]) {
                int j = pos[R[i]];
                swap(P[i], P[j]);
                pos[P[i]] = i;
                pos[P[j]] = j;
                ops.push_back({ i + 1, j + 1 });
            }
        }

        if (ops.size() > n) {
            cout << -1 << endl;
            continue;
        }

        cout << ops.size() << endl;
        for (auto op : ops)
            cout << op.first << " " << op.second << endl;
    }
    return 0;
}
