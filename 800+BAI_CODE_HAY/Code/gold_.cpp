#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Coin {
    int u, v, e;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C;
    cin >> A >> B >> C;
    int n = A + B + C;
    vector<Coin> kids(n);
    for (int i = 0; i < n; ++i) {
        cin >> kids[i].u >> kids[i].v >> kids[i].e;
    }

    // Prefix: top A U values
    vector<ll> pre(n + 1); // pre[i] = max sum of A U values in [0..i-1]
    priority_queue<int, vector<int>, greater<int>> minU;
    ll sumU = 0;
    for (int i = 0; i < n; ++i) {
        minU.push(kids[i].u);
        sumU += kids[i].u;
        if ((int)minU.size() > A) {
            sumU -= minU.top();
            minU.pop();
        }
        if ((int)minU.size() == A)
            pre[i + 1] = sumU;
        else
            pre[i + 1] = -1; // chưa đủ A em
    }

    // Suffix: top B V values
    vector<ll> suf(n + 1); // suf[i] = max sum of B V values in [i..n-1]
    priority_queue<int, vector<int>, greater<int>> minV;
    ll sumV = 0;
    for (int i = n - 1; i >= 0; --i) {
        minV.push(kids[i].v);
        sumV += kids[i].v;
        if ((int)minV.size() > B) {
            sumV -= minV.top();
            minV.pop();
        }
        if ((int)minV.size() == B)
            suf[i] = sumV;
        else
            suf[i] = -1;
    }

    // Tổng tất cả E
    ll totalE = 0;
    for (int i = 0; i < n; ++i)
        totalE += kids[i].e;

    // Duyệt tất cả điểm tách nhóm A và B
    ll res = 0;
    for (int i = A; i <= n - C; ++i) {
        if (pre[i] == -1 || suf[i] == -1) continue;

        // Nhóm C là [0..A-1) + [i+B..n-1]
        // => E nhóm C = totalE - (E nhóm A + E nhóm B)
        ll sumE = totalE;
        for (int j = i - A; j < i; ++j) {
            sumE -= kids[j].e;
        }
        for (int j = i; j < i + B; ++j) {
            sumE -= kids[j].e;
        }

        ll totalScore = pre[i] + suf[i] + sumE;
        res = max(res, totalScore);
    }

    cout << res << '\n';
    return 0;
}
