import math
import random

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def pollards_rho(n):
    if n % 2 == 0:
        return 2
    x = random.randint(2, n-1)
    y = x
    c = random.randint(1, n-1)
    d = 1
    while d == 1:
        x = (x * x + c) % n
        y = (y * y + c) % n
        y = (y * y + c) % n
        d = gcd(abs(x - y), n)
    return d

def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def prime_factors(n):
    factors = []
    while n > 1:
        if is_prime(n):
            factors.append(n)
            break
        factor = pollards_rho(n)
        while n % factor == 0:
            factors.append(factor)
            n //= factor
    return factors

# Ví dụ:
n = 100000000000000000
print(f"Các thừa số nguyên tố của {n} là: {prime_factors(n)}")
