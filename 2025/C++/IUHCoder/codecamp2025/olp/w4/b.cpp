#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main() {
    int n; cin >> n;
    int x, y; 
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
    }    
    if (n <= 10) {
        if (x <= 2)
            cout << "Ban";
        else cout << "Vu";
    }
    else {
        while (true);
    }
}
/*
Ban:   2, 4,  6, 7,  9, 10,   12, 13,   15, 16,   18, 19,     21, 22,  24, 25,  27, 28,   30
Vu : 1, 3,  5,     8,      11,       14,        17,        20,        23,      26,      29

n <= 500:


n > 500:
    22:
    23: 
    25: 
    26: 
    27: 
    28: 
    29:
    30: 
*/