#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, q;
string s;

void subtask1() {
    int l, r; cin >> l >> r;
    vector<int> freq(26, 0);
    for (int i = l; i <= r; i++) {
        freq[s[i] - 'a']++;
    }
        
    int odd = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) odd++;
    }
    int ans = odd / 2;
    cout << ans << endl;
}

void subtask2() {

}

signed main() {

    cin >> n >> q;
    cin >> s;

    if (q == 1) return subtask1(), 0;
    return subtask2(), 0;
}