int main() {	
	map<int, int> ma;
	vector<int>a;
	int n; int ans = 0;
	while (cin >> n) {
		if (n == -1) {
			break;
		}
		if (n == 0) {
			for (int i : a) {
				if (i % 2 == 1) continue;
				ans += ma[i / 2];
			}
			cout << ans << endl;
			ans = 0;
			ma.clear();
			a.clear();
			continue;
		}
		a.push_back(n);
		ma[n]++;
	}
}