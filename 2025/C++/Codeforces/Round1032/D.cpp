#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        vector<int> b(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
   
        vector<pair<int,int>> ope;

        for (int i = 1; i <= n; i++) {
            if (a[i] > b[i]) {
                ope.push_back({3, i});
                swap(a[i], b[i]);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < n; j++) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                    ope.push_back({1, j});
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < n; j++) {
                if (b[j] > b[j + 1]) {
                    swap(b[j], b[j + 1]);
                    ope.push_back({2, j});
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] > b[i]) {
                ope.push_back({3, i});
                swap(a[i], b[i]);
            }
        }

        cout << ope.size() << endl;
        for (auto [p, i] : ope) {
            cout << p << " " << i << endl;
        }

    }
}