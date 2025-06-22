#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t; cin >> t;
    while(t--) {
        int n, s, x; cin >> n >> s >> x;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<int> temp;
        vector<vector<int>> arr;

        for (int i = 1; i <= n; i++) {
            if (a[i] > x) {
                if (temp.empty()) {
                    continue;
                }
                else {
                    arr.push_back(temp);
                    temp.clear();
                }
            }
            else {
                temp.push_back(a[i]);
            }
        }
        if (temp.empty() == false) {
            arr.push_back(temp);
        }

        int res = 0;
        for (auto v : arr) {
            map<int,int> ma;
            ma[0] = 1;
            int m = v.size();
            int pf = 0;
            int total = 0;
            for (int i = 0; i < m; i++) {
                pf += v[i];
                total += ma[pf - s];
                ma[pf]++;
            }
            int without_x = 0;
            vector<int> sub;
            for (int i = 0; i < v.size(); i++) {
                if (v[i] == x) {
                    if (!sub.empty()) {
                        map<int,int> cnt;
                        cnt[0] = 1;
                        int sum = 0;
                        for (int j = 0; j < sub.size(); j++) {
                            sum += sub[j];
                            without_x += cnt[sum - s];
                            cnt[sum]++;
                        }
                        sub.clear();
                    }
                } else {
                    sub.push_back(v[i]);
                }
            }
            if (!sub.empty()) {
                map<int,int> cnt;
                cnt[0] = 1;
                int sum = 0;
                for (int j = 0; j < sub.size(); j++) {
                    sum += sub[j];
                    without_x += cnt[sum - s];
                    cnt[sum]++;
                }
            }

            res += (total - without_x);
        }
        cout << res << endl;
    }
}