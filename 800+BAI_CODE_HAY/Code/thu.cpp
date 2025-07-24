#include <bits/stdc++.h>
using namespace std;


void com1(string &s, vector<int> &list)
{
	int m = 0, n = 0;
	int id = 0;
	while (s[id] != '.')
	{
		if (isdigit(s[id]))
			m = m * 10 + (s[id] - '0');
		id++; 
	}
	while (s[id] != ']')
	{
		if (isdigit(s[id]))
			n = n * 10 + (s[id] - '0');
		id++;
	}
	for (int i = m; i <= n; i++)
		list.push_back(i);
}

void com2(string &s, vector<int> &list)
{
	int cur = 0, id = 0;
	while (s[id] != ']')
	{
		if (s[id] >= '0' && s[id] <= '9')
			cur = cur * 10 + (s[id] - '0');
		if (s[id] == ',')
			list.push_back(cur), cur = 0;
		id++;
		if (s[id] == ']')
			list.push_back(cur), cur = 0;
	}
}

bool checking(string &s)
{
	int dem = 0;
	for (char c : s)
		dem += (c == '.');
	return (dem != 0);
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; getline(cin, s);
	int a = 0, b = 0;
	vector<char> dau = {'+', '+'};
	s = " " + s;
	int id = 1;
	while (s[id] != ',')
	{
		if (s[id] == '*' || s[id] == '+' || s[id] == '-')
			dau[0] = s[id];
		if (s[id] >= '0' && s[id] <= '9')
			a = a * 10 + (s[id] - '0');
		id++;
	}
	while (s[id] != ')')
	{
		if (s[id] == '*' || s[id] == '+' || s[id] == '-')
			dau[1] = s[id];
		if (s[id] >= '0' && s[id] <= '9')
			b = b * 10 + (s[id] - '0');
		id++;
	}

	string s1 = "", s2 = "";
	vector<int> list1, list2;

	while (s[id] != ']')	
		s1.push_back(s[id++]);
	s1.push_back(s[id++]);
	
	while (s[id] != '[')
		id++;

	while (s[id] != ']')	
		s2.push_back(s[id++]);
	s2.push_back(s[id++]);


	if (checking(s1))
		com1(s1, list1);
	else
		com2(s1, list1);

	if (checking(s2))
		com1(s2, list2);
	else 
		com2(s2, list2);

	
	// for (int c : list1)
	// 	cout << c << ' ';
	// cout << '\n';
	// for (int c : list2)
	// 	cout << c << ' ';

	int K = list1.size();
	cout << '[';
	for (int i = 0; i < K; i++)
	for (int j = 0; j < list2.size(); j++)
	{
		int x = list1[i], y = list2[j];
		if (dau[0] == '*')
			x *= a;
		if (dau[0] == '+')
			x += a;
		if (dau[0] == '-')
			x -= a;

		if (dau[1] == '*')
			y *= b;
		if (dau[1] == '+')
			y += b;
		if (dau[1] == '-')
			y -= b;
		cout << '(' << x << ',' << y << ')';
		if ((i + 1) * (j + 1) != list1.size() * list2.size())
			cout << ", ";
	}
	cout << ']';


}