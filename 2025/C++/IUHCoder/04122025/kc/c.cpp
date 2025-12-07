#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m; 
vector<vector<int>> a;
const int MOD = 1e9 + 7;

bool checkSubtask1() {
    return n == 1;
}
// n : row
// m : col

bool checkSubtask2() {
    return n <= 100 && m <= 100;
}
void doSubtask1() {
    int cnt =  0;
    for (int j = 1; j <= m; j++) {
        if (a[j][1] == 3) cnt++;
    }
    cout << cnt;
}

void doSubtask2() {
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        int l = -1, r= -1;
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 3) {
                if (l == -1) {
                    l = j;
                }
                else {
                    r = j;
                }
            }    
        }
        if (l == -1 && r == -1) continue;
        if (l == -1) continue;
        if (r == -1) { cnt++; continue;}
        cnt += r - l + 1;
    }
    cout << cnt;
}

void doSubtask3() {
    cout << 0;
}
signed main() {
    cin >> n >> m;
    a.resize(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    if (checkSubtask1()) return doSubtask1(), 0;
    if (checkSubtask2()) return doSubtask2(), 0;
    doSubtask3();
}
