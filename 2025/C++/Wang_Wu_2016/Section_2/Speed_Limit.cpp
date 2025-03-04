#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n; 
	while (cin >> n && n != -1) {
		vector<pair<int, int>> a(n);
		for (int i = 0; i < n; i++) {
			int speed, time;
			cin >> speed >> time;
			a[i] = { speed, time };
		}
		int distance = a[0].first * a[0].second;
		for (int i = 1; i < n; i++) {
			distance += a[i].first * (a[i].second - a[i - 1].second);
		}
		cout << distance << " miles"<< endl;

	}

}