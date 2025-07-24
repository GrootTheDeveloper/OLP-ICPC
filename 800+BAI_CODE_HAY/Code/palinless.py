t = int(input())
for _ in range(t):
	s = input()
	s = s + s[0]
	l,r = 0,len(s) - 1
	while l<=r:
		if (s[l] == s[r]):
			r-=1
			l+=1
		else:
			break
	if (r < l):
		print("YES")
	else:
		print("NO")