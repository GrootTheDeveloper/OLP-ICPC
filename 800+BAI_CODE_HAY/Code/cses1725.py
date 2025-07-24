dp=[]
for i in range(111):
	dp.append([0]*666)

dp[0][0]=1
n,a,b=map(int,input().split())

for i in range(1,n+1):
	for c in range(1,7):
		for j in range (c,n*6+1):
			dp[i][j]=dp[i][j]+dp[i-1][j-c]
omega,bc=0,0
for i in range(1,n*6+1):
	omega=omega+dp[n][i]
	if (a<=i<=b):
		bc=bc+dp[n][i]
print("{0:.6f}".format(round(bc/omega,6)))