#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n; 
vector<int>a;
bool checkSubtask1() {
    return n <= 10;
}
bool checkSubtask2() {
    for (int i = 1; i <= n; i++) {
        int x = sqrt(a[i]);
        if (x * x != a[i]) return false;
    }
    return true;
}
bool checkSq(vector<int> b) {
    int ans = 1;
    for (auto i : b) ans *= i;
    int x = sqrt(ans);
    return x * x == ans; 
}

void doSubtask1() {
    int maxLen = 0;
    for (int r = 1; r <= n; r++) {
        for (int l = 1; l <= r; l++) {
            vector<int> cur;
            for (int i = l; i <= r; i++) cur.push_back(a[i]);
            int newN = (r - l  + 1);
            int mask = 1 << newN;
            bool check = false;
            for (int i = 0; i < mask; i++) {
                vector<int> b;
                for (int j = 0; j < newN; j++) {
                    if (i & (1 << j)) {
                        b.push_back(cur[j]);
                    }
                }
                if (b.empty() == false && checkSq(b)) {
                    check = true;
                    break;
                }
            }
            if (check == false) maxLen = max(maxLen, newN);
        }
    }

    cout << maxLen;
}

void doSubtask2() {
    cout << 0;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)cin >> a[i];
    if (checkSubtask1()) return doSubtask1(), 0;
    if (checkSubtask2()) return doSubtask2(), 0;
}