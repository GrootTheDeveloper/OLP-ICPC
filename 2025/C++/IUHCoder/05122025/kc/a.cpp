#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int oo = 1e18;
const int MOD = 1e9 + 7;
int a, b, c, d;
int t; 

bool checkSubtask1() {
    return true;
}

void doSubtask1() {
    int f = 1, s = 1;
    for (int i = a; i <= b; i++) {
        f *= i;
    }
    for (int i = c; i <= d; i++) {
        s *= i;
    }
    if (s % f == 0) cout << "Y";
    else cout << "N";
    cout << endl;
}

void doSubtask2() {
    
}

signed main() {
    vector<int> check;
    cin >> t;
    int test = t;
    while (t--) {
        cin >> a >> b >> c >> d;
        if (checkSubtask1()) doSubtask1();
//        if (checkSubtask2()) return doSubtask2(), 0;
    }
}

/*
t = 1
test 19, 20 : Y

*/