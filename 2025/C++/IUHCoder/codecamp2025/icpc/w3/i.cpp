#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

bool check(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > 0) return false;
    }
    return true;
}

signed main() {
    int n; cin >> n;
    vector<int> tab(n + 1), expected(n + 1);
    for (int i = 1; i <= n; i++) cin >> tab[i];
    for (int i = 1; i <= n; i++) cin >> expected[i];
    
    int i = 1, j = 1;
    vector<int> temp;
    int ope = 0;
    while (i <= n) {
        if (temp.empty()) {
            temp.push_back(tab[i] - expected[i]);
        }
        else {
            int diff = tab[i] - expected[i];
            if (diff == 0) {
                i++;
                for (auto &c : temp) c = abs(c);
                int maxVal = -1;
                for (auto c : temp)
                    maxVal = max(maxVal, c);
                ope += maxVal;
                continue;
            }
            int maxVal = -1;
            if (diff > 0) {
                if (temp.back() < 0) {
                    for (auto &c : temp) {
                        c = abs(c);
                    }
                    for (auto c : temp)
                        maxVal = max(maxVal, c);
                    ope += maxVal;
                    temp.clear();
                    temp.push_back(diff);
                }
                else {
                    temp.push_back(diff);
                }
            }
            else {
                if (temp.back() > 0) {
                    for (auto c : temp)
                        maxVal = max(maxVal, c);
                    ope += maxVal;
                    temp.clear();
                    temp.push_back(diff);
                }
                else {
                    temp.push_back(diff);
                }
            }
        }
        i++;
    }
    if (temp.empty() == false) {
        for (auto &c : temp) c = abs(c);
        int maxVal = -1;
        for (auto c : temp)
            maxVal = max(maxVal, c);
        ope += maxVal;
    }
    cout << ope;
}