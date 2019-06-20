import math
pi = math.pi
def rec_cal(A, n, si):
    if(int(n) == 1):
        return A
    w = complex(math.cos(si*2*pi/n), math.sin(si*2*pi/n))
    odd, even = A[1::2], A[0::2]
    odd_f = rec_cal(odd,(n/2), si)
    even_f = rec_cal(even, (n/2), si)
    ret = [0. for i in range(int(n))]
    for i in range(int(n/2)):
        z = complex(math.cos(i*si*2*pi/n), math.sin(i*si*2*pi/n))*odd_f[int(i)]
        ret[int(i)] = even_f[int(i)] + z
        ret[int(n/2) + int(i)] = even_f[int(i)] - z
    return ret
n, m = input().split(" ")
Ar, Ai, Br, Bi = input().split(" "), input().split(" "), input().split(" "), input().split(" ")
for i in range(int(n)):
    Ar[i] = complex(float(Ar[i]), float(Ai[i]))
for i in range(int(m)):
    Br[i] = complex(float(Br[i]), float(Bi[i]))
n, m=int(n), int(m)
s=n+m-1
if(int(math.log2(n+m-1)) != math.log2(n+m-1)):
    p = 2**(int(math.log2(n+m-1)) + 1)
else:
    p = s
Ar = Ar[:n]
if(n<p):
    for i in range(n, p):
        Ar.append(complex(0, 0))
    n = p
Br = Br[:m]
if(m<p):
    for i in range(m, p):
        Br.append(complex(0, 0))
    m = p
A = rec_cal(Ar, p, 1.)
B = rec_cal(Br, p, 1.)
P = [a*b for a, b in zip(A, B)]
X = rec_cal(P, p, -1.)
for i in range(s):
    X[i] = X[i] / len(A)
for i in range(s):
    if(i!=s-1):
        if((X[i].real <= 0) and (X[i].real > -0.000005)):
            print("0.00000", end = " ")
        else:
            print("%.5f" %(X[i].real), end = " ")
    else:
        if((X[i].real <= 0) and (X[i].real > -0.000005)):
            print("0.00000")
        else:
            print("%.5f" %(X[i].real))
for i in range(s):
    if((X[i].imag <= 0) and (X[i].imag > -0.000005)):
        print("0.00000", end = " ")
    else:
        print("%.5f" %(X[i].imag), end = " ")
