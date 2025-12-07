#include <bits/stdc++.h>
#define int long long  
using namespace std;

signed main() {
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    vector<vector<int>> f(n + 1, vector<int>(26, 0)); // f[i] : chứa số lượng ['a'..'z'] khi xét i ký tự ban đầu

    vector<pair<int,int>> ch; // ch[i] = {j, k} -> j là vị trí đầu tiên, k là vị trí cuối cùng của đoạn liên tục 

    int first = 1, second = 1;

    vector<vector<int>> idx(26, vector<int>());
    for (int i = 2; i <= n; i++) {
        if (s[i] == s[first]) {
            second = i;
        }
        else {
            ch.push_back({first, second});
            first = second = i;
        }
    }   
    ch.push_back({first, second});

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            f[i][j] = f[i - 1][j];
        }
        f[i][s[i] - 'a']++;
        idx[s[i] - 'a'].push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < ch.size(); i++) {
        int len = ch[i].second - ch[i].first + 1;
        if (len >= 2) {
            ans += len - 1;
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 1; j < idx[i].size(); j++) {
            int first = idx[i][j - 1];
            int second = idx[i][j];

            int len = second - first + 1;
            if (len <= 2) continue;

            vector<int> temp(26, 0);
            for (int k = 0; k < 26; k++) {
                temp[k] = f[second - 1][k] - f[first][k];
            }
            bool oneChar = false;
            bool check = true;
            for (int k = 0; k < 26; k++) {
                if (temp[k] > 0) {
                    if (oneChar == true) {
                        check = false;
                        break;
                    }
                    oneChar = true;
                }
            }
            if (check == false) continue;
            if (oneChar == true) {
                if (s[first] != s[first + 1]) {
                    ans++;
                }
            }
        }
    }

    cout << ans;
}