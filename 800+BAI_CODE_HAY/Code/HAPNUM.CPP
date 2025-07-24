#include <bits/stdc++.h>
using namespace std;
struct BigNum {
    string num;

    BigNum(string s = "0") {
        while (s.size() > 1 && s[0] == '0') s.erase(s.begin());
        num = s;
    }

 
    BigNum operator + (const BigNum &other) const {
        string a = num, b = other.num;
        if (a.size() < b.size()) swap(a, b);
        while (b.size() < a.size()) b = '0' + b;

        string res = "";
        int carry = 0;
        for (int i = a.size() - 1; i >= 0; --i) {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            res += (sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry) res += (carry + '0');
        reverse(res.begin(), res.end());
        return BigNum(res);
    }

    BigNum operator * (const BigNum &other) const {
        int n = num.size(), m = other.num.size();
        vector<int> res(n + m, 0);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int mul = (num[i] - '0') * (other.num[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + res[p2];
                res[p2] = sum % 10;
                res[p1] += sum / 10;
            }
        }

        string result = "";
        for (int digit : res)
            if (!(result.empty() && digit == 0))
                result += (digit + '0');
        return BigNum(result.empty() ? "0" : result);
    }

    void print() const {
        cout << num;
    }
};
BigNum base("1");
struct node{
	int sum, lef, mid, rig;
	node(): sum(0), lef(0), mid(0), rig(0){};
	node(int a, int b, int c, int d): sum(a), lef(b), mid(c), rig(d){};
};
int m, k, x[20];
node a[111];
int calc_sum(int l, int r){
	int ans = 0;
	for (int i = l; i <= r; i++)
		ans += x[i];
	return ans;
}
void input(){
	cin >> m >> k;
	for (int i = 1; i <= m; i++){
		int ai; cin >> ai;
		int lim = 0;
		while (ai){
			x[++lim] = ai % 10;
			ai /= 10;
		}
		reverse(x + 1, x + lim + 1);
		int mid = k / 2 + (k & 1);
		if (k & 1)
			a[i] = node(calc_sum(1, k), calc_sum(1, mid - 1), calc_sum(mid, mid), calc_sum(mid + 1, k));
		else
			a[i] = node(calc_sum(1, k), calc_sum(1, mid), 0, calc_sum(mid + 1, k));
	}
	for (int i = 1; i <= m / 2; i++){
		base = base * BigNum(to_string(i));
	}
	base = base * base;
}
string To_string(__int128 x) {
    if (x == 0) return "0";
    bool neg = false;
    if (x < 0) {
        neg = true;
        x = -x;
    }
    string res = "";
    while (x > 0) {
        res += char(x % 10 + '0');
        x /= 10;
    }
    if (neg) res += '-';
    reverse(res.begin(), res.end());
    return res;
}

__int128 dp[51][4055];
void calc1(){	
	int SUM = 0;
	for (int i = 1; i <= m; i++)
		SUM += a[i].sum;
	__int128 ans = 0;
	for (int id = 1; id <= m; id++){
		if ((SUM - a[id].mid) & 1)
			continue;
		int acpt = (SUM - a[id].mid) / 2 - a[id].lef;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (int i = 1; i <= m; i++){
			if (i == id) continue;
			for (int cnt = m / 2; cnt >= 1; cnt--)
				for (int s = acpt; s >= a[i].sum; s--)
					dp[cnt][s] += dp[cnt - 1][s - a[i].sum];
		}
		ans += dp[m / 2][acpt];
	}
	BigNum res(To_string(ans));
	res = res * base;
	res.print();
}
void calc2(){
	int SUM = 0;
	for (int i = 1; i <= m; i++)
		SUM += a[i].sum;
	__int128 ans = 0;
	if (SUM & 1)
		return cout << 0, void();
	int acpt = SUM / 2;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i = 1; i <= m; i++){
		for (int cnt = m / 2; cnt >= 1; cnt--)
			for (int s = acpt; s >= a[i].sum; s--)
				dp[cnt][s] += dp[cnt - 1][s - a[i].sum];
	}
	ans += dp[m / 2][acpt];
	
	BigNum res(To_string(ans));
	res = res * base;
	res.print();
}
void solve(){
	if (m & 1)
		calc1();
	else
		calc2();
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	solve();
}