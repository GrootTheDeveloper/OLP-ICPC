#include <bits/stdc++.h>
#define int long long

using namespace std;

double calc(int x1, int y1, int x2, int y2) {
    double res = (x2 - x1) * (x2 - x1) + (y2-y1) * (y2-y1);
    res = sqrt(res);
    return res;
}

signed main() {
    int n, f0, d;
    cin >> n >> f0 >> d;
    vector<pair<int,int>> people(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> people[i].first >> people[i].second;
    }
    vector<bool> check(n + 1, false); // Thằng này đã được kiểm tra chưa?

    check[f0] = true;

    int cntF1 = 0;

    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (check[i] == false) {
            
            int dist = calc(people[f0].first, people[f0].second , people[i].first, people[i].second);
            if (dist < d) {
                q.push(i);
                cntF1++;
                check[i] = true;
            }
        }    
    }

    int cntF2 = 0;
    while (!q.empty()) {
        int currentPeople = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (check[i] == false) {
                int dist = calc(people[currentPeople].first, people[currentPeople].second, people[i].first, people[i].second);
                if (dist < d) {
                    cntF2++;
                    check[i] = true;
                }
            }
        }
    }

    cout << cntF1 << " " << cntF2;

    return 0;
}
