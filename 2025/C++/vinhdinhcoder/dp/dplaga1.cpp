#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

struct BigNum {
    string s;
    
    BigNum(string t = "0") {
        if (t.empty()) s = "0";
        s = t;
    }

    BigNum operator + (const BigNum &other) {
        vector<int> fi,se;

        string a = s;
        string b = other.s;
    
        for (auto &c : a) {
            fi.push_back(c - '0');
        }
        for (auto &c : b) {
            se.push_back(c - '0');
        }
        reverse(fi.begin(), fi.end());
        reverse(se.begin(), se.end());
        while(se.size() < fi.size()) {
            se.push_back(0);
        }
        int n = fi.size();
        int rem = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int digit = fi[i] + se[i] + rem;
            rem = digit / 10;
            ans.push_back(digit % 10);
        }
        if (rem != 0) {
            ans.push_back(rem);
        }
        string res;
        for (auto c : ans) {
            res += to_string(c);
        }
        reverse(res.begin(), res.end());
        return BigNum(res);
    }

};

int main(){
//    freopen("dplaga1.inp", "r", stdin);
//    freopen("dplaga1.out", "w", stdout);
    
    int t; cin >> t;
    vector<BigNum> dp(201);
    dp[1] = BigNum("1");
    dp[2] = BigNum("2");
    for (int i = 3; i <= 200; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    while(t--) {
        int n;
        cin >> n;
        cout << dp[n].s << endl;
    }
    return 0;
}