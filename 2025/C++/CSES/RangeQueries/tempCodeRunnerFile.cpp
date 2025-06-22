#include <bits/stdc++.h>
#define int long long
using namespace std;

int calc(int n) {
    int t = 0;
    while(n) {
        t += n % 10;
        n/=10;
    }
    return t;
}

signed main(){
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        string a;
        int total = stoll(s);

        int D = total / 2;
        int M = total / 2;
        int diff = total % 2;

        if (abs(calc(D + diff) - calc(M)) <= 1) {
            cout << D + diff << " " << M << endl;
            continue;
        }
        if (abs(calc(D - diff) - calc(M)) <= 1) {
            cout << D - diff << " " << M << endl;
                        continue;
         }
        if (abs(calc(D) - calc(M - diff)) <= 1) {
            cout << D  << " " << M - diff<< endl;
                        continue;
        }
        if (abs(calc(D) - calc(M + diff)) <= 1) {
            cout << D << " " << M + diff << endl;
                        continue;
        }

        string numLeft;
        string numRight;

        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                numLeft += s[i];
            }
            else {
                numRight += s[i];
            }
        }

        int sumLeft = 0;
        int sumRight = 0;

        for (auto c : numLeft) {
            sumLeft += c - '0';
        }
        for (auto c : numRight) {
            sumRight += c - '0';
        }

        for (int i = 0; i < numRight.size(); i++) {
            numLeft.push_back('0');
        }

        int tL, tR;
        if (numLeft.empty() == false) {
            tL = stoll(numLeft);
        }
        else {
            tL = 0;
        }
        if (numRight.empty() == false) {
            tR = stoll(numRight);
        }
        else {
            tR = 0;
        }

        while (abs(sumLeft - sumRight) > 1) {
            if (sumLeft > sumRight) {
                sumLeft--;
                sumRight++;
                tL--;
                tR++;
            }
            else {
                sumLeft++;
                sumRight--;
                tL++;
                tR--;
            }
        }
        cout << tL << " " << tR << endl;
    }
}