import primer
import sys

primorials = []
for i in range(int(sys.argv[1])):
    primorials.append(primer.primorial(i+1))

def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

p1 = [e + 1 for e in primorials]

for i in range(len(p1)):
    s = str(p1[i]) + ' : ' + str(prime_factors(p1[i]))
    print s
