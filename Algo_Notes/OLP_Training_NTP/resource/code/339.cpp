#include <bits/stdc++.h>
using namespace std;

int p, n, q;
string s;
vector<pair<int,int>> queries;
bool checkSubtask1() {
    return s.size() <= 1e4;
}

void doSubtask1() {
    for (int Q = 1; Q <= q; Q++) {
        int l = queries[Q].first, r = queries[Q].second;
        int ans = 0;

        string str;
        for (int i = l; i <= r; i++) {
            str += s[i];
        }

        for (int i = 0; i < str.size(); i++) {
            for (int j = i; j < str.size(); j++) {

                string tmp;
                for (int k = i; k <= j; k++) {
                    tmp += str[k];
                }
                if (tmp.empty()) continue;
                int num = stoll(tmp);
                if (num % p == 0) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}

bool checkSubtask2() {
    return p == 2 && s.size() <= 1e5;
}

void doSubtask2() {
    
}

signed main() {
    cin >> p;
    cin >> s;
    n = s.size();
    s = " " + s;
    cin >> q;
    queries.resize(q + 1);
    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;
        queries[i] = {l, r};
    }

    if (checkSubtask1()) return doSubtask1(), 0;
    if (checkSubtask2()) return doSubtask2(), 0;


    return 0;
}
