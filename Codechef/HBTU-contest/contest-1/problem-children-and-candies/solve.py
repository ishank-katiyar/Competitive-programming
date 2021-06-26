import bisect

for t in range(int(input())):
	n, m = map (int, input().split())
	A = [int(x) for x in input().split()]
	for i in range (1, n):
		A[i] += A[i - 1]
	ans = [str(bisect.bisect(A, int(x))) for x in input().split()]
	print (' '.join(ans) + ' ')
