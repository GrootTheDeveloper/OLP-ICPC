#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, k;
string s;
bool checkSubtask1() {
    return n <= 1e2;
}

int id(char c) {
    if (c == 'V') return 0;
    if (c == 'A') return 1;
    return 2;
}

void doSubtask1() {
    int ans = 1e18;
    for (int r = 1; r <= n; r++){
        for (int l = 1; l < r; l++) {
            vector<int> cnt(3, 0);
            
            for (int i = l; i <= r; i++) {
                cnt[id(s[i])]++;
            }

            if (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k) {
                ans = min(ans, (r - l + 1) - 3 * k);
            } 

        }
    }
    if (ans == 1e18) ans = -1;
    cout << ans;
}

void doSubtask2() {
    int ans = 1e18;

    int l = 1;
    vector<int> cnt(3, 0);
    for (int r = 1; r <= n; r++) {
        cnt[id(s[r])]++;
        while (cnt[0] >= k && cnt[1] >= k && cnt[2] >= k) {
            ans = min(ans, (r - l + 1) - 3 * k);
            cnt[id(s[l])]--;
            l++;
        }
    }
    cout << ans;

}

signed main() {
    cin >> k;
    cin >> s;
    n = s.size();
    s = " " + s;
    if (checkSubtask1()) return doSubtask1(), 0;
    doSubtask2();
    return 0;
}
