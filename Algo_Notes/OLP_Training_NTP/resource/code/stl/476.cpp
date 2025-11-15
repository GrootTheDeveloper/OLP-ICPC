#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int q; cin >> q;
    map<int,int> ma;
    map<int, set<int>> freq;
    while (q--) {
        int type; cin >> type; 
        if (type == 1) {
            int x, a; 
            cin >> x >> a;
            int currentFreq = ma[x];
            if (freq.find(currentFreq) != freq.end()) {
                if (freq[currentFreq].find(x) != freq[currentFreq].end()) {
                    freq[currentFreq].erase(x);
                    if (freq[currentFreq].empty()) freq.erase(currentFreq);
                }
            }
            ma[x] += a;
            freq[currentFreq + a].insert(x);
        }
        else if (type == 2) {
            int x, b; cin >> x >> b;
            int currentFreq = ma[x]; // x = 5, currentFreq = 10
            if (currentFreq <= b) { // b = 7, currentFreq = 10 b < currentFreq
                ma.erase(x);
                freq[currentFreq].erase(x);
                if (freq[currentFreq].empty()) freq.erase(currentFreq);
            }
            else {
                ma[x] -= b; // ma[5] = 10 - 7 = ma[5] = 3
                freq[currentFreq].erase(x);  // freq[10] = {}
                if (freq[currentFreq].empty()) freq.erase(currentFreq);
                freq[currentFreq - b].insert(x); // freq[10 - 7 = 3].insert(3)
            }
        }
        else if (type == 3) {            
            auto it = freq.rbegin();
            if (it->second.size() == 1) {
                cout << *it->second.begin() << endl;
            }
            else {
                cout << *it->second.rbegin() << endl;
            }
        }
    }
    return 0;
}