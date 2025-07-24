


x = int(input())
y = int(input())

l = len(str(x * x))
r = len(str(y * y))

def pin(l, r, x):
	ans = r + 1
	while l <= r:
		mid = (l + r) // 2
		if (len(str(mid * mid))) >= x:
			ans = mid
			r = mid - 1
		else:
			l = mid + 1
	return ans

ans = 0
for i in range(l, r + 1):
	p1 = pin(x, y, i)
	p2 = pin(x, y, i + 1)
	ans += i * (p2 - p1)
print(ans)
