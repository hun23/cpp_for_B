# Euclidian Algorithm
GCD : Greatest Commen Divisor
put GCD(a,b) = G
put a = N, b = M
while (true)
{
  a = G\*A
  b = G\*B
  q = a%b (q: natural number G\*B\*q < G\*A)
  if (0==q) break; (At this point, a and b has common divisor of b)
  r = a-b\*q
  r = G\*A - G\*B \*q 
  r = G(A - B\*q)
  r = G\*M (M = A - B\*q, M is a natural number)
  a = b
  b = r
}
G = b
