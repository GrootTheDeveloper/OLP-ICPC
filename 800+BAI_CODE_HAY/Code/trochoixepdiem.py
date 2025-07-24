n=int(input())
if (n%2==1 or n==2):
  print(-1)
  print(-1)
else:
  n//=2
  if n%2==0:
    print(n-1)
    print(n*n//4)
  else:
    print(n-1)
    print((n//2)*(n//2+1))
