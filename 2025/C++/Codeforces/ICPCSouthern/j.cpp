#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    string a, b; cin >> a >> b;
    if (a == b) {
        cout << "Draw";
    }
    else {
        if (a == "Rock") {
            if (b == "Scissors") {
                cout << "Player 1";
            }
            else if (b == "Paper") {
                cout << "Player 2";
            }
        }
        else if (a == "Paper") {
            if (b == "Rock") {
                cout << "Player 1";
            }
            else if (b == "Scissors") {
                cout << "Player 2";
            }
        }
        else if (a == "Scissors") {
            if (b == "Paper") {
                cout << "Player 1";
            }
            else if (b == "Rock") {
                cout << "Player 2";
            }
        }
    }
}
