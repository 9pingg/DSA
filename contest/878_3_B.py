import math
def calculate_num_ways(n, k):
    if (math.log2(n) < k): return n+1
    else: return 2 ** k

t = int(input())  # Number of test cases

for _ in range(t):
    n, k = map(int, input().split())  # Read n and k for each test case
    num_ways = calculate_num_ways(n, k)
    print(num_ways)