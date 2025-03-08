/*
Source: ACM Tehran 2002, First Iran Nationwide Internet Programming Contest.
IDs for online judges: POJ 1019, ZOJ 1410
Status: Compile Error, Time Limited Exceeded (I guess)
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    int T; 
    cin >> T;
	while (T--) {
		int n; cin >> n;
		string s, t;
		for (int i = 1; ; i++) {
			if (s.length() + to_string(i).length() > n) {
				break;
			}
			t += to_string(i);
			s += t;

		}
		cout << s[n - 1] << endl;
	}
}