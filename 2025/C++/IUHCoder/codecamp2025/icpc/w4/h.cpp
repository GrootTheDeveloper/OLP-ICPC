#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

vector<string> ans;
bool check(string s, int k) {
    int cnt = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) {
            cnt++;
            if (cnt > k) return false;
        } else {
            cnt = 1;
        }
    }
    return true;
}

void dq(string current, int n, int k) {
    if (current.size() == n) {
        if (check(current, k))
            ans.push_back(current);
        return;
    }
    dq(current + '0', n, k);
    dq(current + '1', n, k);
}
signed main() {
    int n, k; cin >> n >> k;
    dq("", n, k);
    cout << ans.size();

}