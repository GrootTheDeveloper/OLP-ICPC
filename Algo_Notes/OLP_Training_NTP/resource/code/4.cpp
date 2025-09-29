#include <bits/stdc++.h>
#define int long long
using namespace std;
string s; 
int n;

bool checkSubtask1() {
    return n <= 9;
}
void doSubtask1() {
    int ans = 1e18;
    string firstNumber, secondNumber, thirdNumber;
    firstNumber += s[1];

    for (int first = 2; first < n; first++) {

        for (int second = first + 1; second <= n; second++) {
            secondNumber.clear(), thirdNumber.clear();
            
            for (int i = first; i < second; i++) {
                secondNumber += s[i];
            }

            for (int i = second; i <= n; i++) {
                thirdNumber += s[i];
            }

            if (secondNumber.empty() || thirdNumber.empty()) continue;
            if (secondNumber[0] == '0' && secondNumber.size() > 1) continue;
            if (thirdNumber[0] == '0' && thirdNumber.size() > 1) continue;

            int fNum = stoll(firstNumber);
            int sNum = stoll(secondNumber);
            int tNum = stoll(thirdNumber);

            int res = fNum + sNum + tNum;
//            cout << fNum << ' ' << sNum << ' ' << tNum << endl;
            ans = min(ans, res);

        }

        firstNumber += s[first];
    }
    cout << ans;
}
bool checkSubtask2() {
    return n <= 5*1e3;
}

void doSubtask2() {
    
}

signed main() {
    cin >> s;
    n = s.size();
    s = " " + s;
    if (checkSubtask1()) return doSubtask1(), 0;
    if (checkSubtask2()) return doSubtask2(), 0;
    return 0;
}
