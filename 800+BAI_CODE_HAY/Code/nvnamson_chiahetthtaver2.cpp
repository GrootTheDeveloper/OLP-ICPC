#include <bits/stdc++.h>
using namespace std;
#define int long long 
int m,cnt[10];
string n;
string comp(vector <int> v)
{
	sort(v.begin(),v.end(),greater<int>());
	string s = "";
	for (int &c : v) s=s+to_string(c);
	return s;
}
vector <int> cof(string s)
{
	vector <int> res;
	res.resize((int)s.size());
	for (int i = 0; i < s.size(); i++) res[i]=s[i];
	return res;

}
void div2()
{
	bool dec = false;
	int val = -1;
	for (int i = 0; i < 9 && !dec; i += 2) if (cnt[i]) cnt[i]--,val = i,dec = true;
	if (val == -1) return cout << 0,void();
	
	for (int i = 9; i >= 0; i--)
		while (cnt[i]) cout << i, cnt[i]--;
	cout << val;
}
void div4()
{
	if (n == "4" || n == "8") return cout << n,void();
	bool dec = false;
	string val = "999";
	for (int i = 0; i <= 9; i++)
		if (cnt[i] > 1 && (i*10+i) % 4 ==0 && comp(cof(val)) > comp({i,i})) val=to_string(i)+to_string(i);
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j <= 9; j++)
			if (i!=j && cnt[i] && cnt[j] && (i*10+j)%4==0 && comp(cof(val)) > comp({i,j})) val=to_string(i)+to_string(j);
	if (val=="999") return cout << 0,void();
	cnt[val[1]-'0']--;
	cnt[val[0]-'0']--;
	for (int i = 9; i >= 0; i--)
		while (cnt[i]) cout << i, cnt[i]--;
	cout << val;



	

}
void div6()
{
	bool dec = false;
	int val = -1;
	for (int i = 0; i < 9 && !dec; i += 2) if (cnt[i]) cnt[i]--,val = i,dec = true;
	if (val == -1) return cout << 0,void();
	
	int sum = val;
	for (int i = 1; i <= 9; ++i) sum += i * cnt[i];
	if (sum % 3 !=0) return cout << 0,void();
	for (int i = 9; i >= 0; i--) 
		while (cnt[i]) cout << i, cnt[i]--;
	cout << val;
}
void div8()
{
	for (int i = 8; i<=100; i+=8) if (n==to_string(i)) return cout << n,void();
	bool dec = false;
	string val = "999";
	
	for (int i = 0; i <= 9; i++)
		for (int j=0; j<=9;j++)
			for(int z=0;z<=9;z++)
			{
				cnt[i]--;
				cnt[j]--;
				cnt[z]--;
				if (cnt[i]>=0 && cnt[j]>=0 && cnt[z]>=0&& (i*100+j*10+z)%8==0 && comp(cof(val)) >= comp({i,j,z})) val=to_string(i)+to_string(j)+to_string(z);
				cnt[i]++;cnt[z]++;cnt[j]++;
			}

	if (val=="999") return cout << 0,void();
	cnt[val[1]-'0']--;
	cnt[val[0]-'0']--;
	cnt[val[2]-'0']--;
	for (int i = 9; i >= 0; i--)
		while (cnt[i]) cout << i, cnt[i]--;
	cout << val;

}
void div10()
{
	if (cnt[0] == 0) return cout << 0,void();
	for (int i = 9; i >=0; --i) 
		while (cnt[i]) cout << i, cnt[i]--;
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0); 
	cin >> n;
	cin >> m;
	for (char c : n) cnt[c - '0'] ++; 
	switch (m)
	{
		case 2:
			div2();
			break;
		case 4:
			div4();
			break;
		case 6:
			div6();
			break;
		case 8:
			div8();
			break;
		case 10:
			div10();
			break;
		default:
			cout << "Cut me m di";
			break;
	} 

}