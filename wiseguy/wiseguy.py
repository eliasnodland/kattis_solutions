import numpy as np

# This function shifts an array a to the right by 1 filling with 0's (The first
# element becomes 0)
def shift(a):
    for i in range(len(a) - 1, 0, -1):
        a[i] = a[i - 1]
    a[0] = 0

N = 10 + 1

# Prepare matrices
P = np.zeros((N, N))

# Initialize with known probabilities
P[:, 0] = np.ones((1, N))
P[:, 1] = np.ones((1, N))

for k in range(2, N):
    for l in range(0, k):
        r = k - l - 1
        P[:, k] += np.multiply(P[:, l], P[:, r])
    P[:, k] = np.divide(P[:, k], k)
    shift(P[:, k])

# The result is currently cumulative meaning that P[n][h] = P(H <= h) for some n
# This loop reverses that by observing that P(H = h) = P(H <= h) - P(H <= h-1)
for k in range(0, N):
    for i in range(N - 1, 0, -1):
        P[i, k] -= P[i - 1, k]

# For every n, go through all probabilities and multiply with corresponding
# height and sum up to get expected height. E(H) = sum(h * P(H = h))
E = np.zeros(N)
for n in range(1, N):
    s = 0
    for h in range(0, N, 1):
        s += P[h, n] * h;
    E[n] = s

E[0] = -1.0 # Height of tree with 0 nodes is -1. Included for completeness

# Print the results in two columns, N on the left and E(H) on the right
print("n,\te")
for n in range(0, N):
    print("%s,\t%s" % (n, E[n]))
