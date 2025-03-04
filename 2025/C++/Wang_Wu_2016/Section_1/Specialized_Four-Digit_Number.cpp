#include <bits/stdc++.h>
using namespace std;

int calc(int n, int base) {
	int ans = 0;
	while (n) {
		ans += n % base;
		n /= base;
	}
	return ans;
}

int main() {

	for (int i = 2991; i <= 9999; i++) {
		if (calc(i, 10) == calc(i, 16) && calc(i, 10) == calc(i, 12)) {
			cout << i << endl;
		}
	}
}