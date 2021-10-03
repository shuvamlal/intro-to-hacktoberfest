def solve(arr, n, sum, t):
    # base case condition
    if n==0 and sum != 0:
        t[n][sum] = 0
        return t[n][sum]
    elif sum==0:
        t[n][sum] = 1
        return t[n][sum]
    
    # condition after memoiztion
    elif t[n][sum] != None:
        return t[n][sum]
    
    # conditions subset sum count
    elif arr[n-1] <= sum:
        t[n][sum] = solve(arr, n-1, sum-arr[n-1], t) + solve(arr, n-1, sum, t)
        return t[n][sum]
    elif arr[n-1] > sum:
        t[n][sum] = solve(arr, n-1, sum, t)
        return t[n][sum]

arr = [1,3,4]
sum = 4
n = len(arr)
t = [[None]*(sum+1) for _ in range(n+1)]
cnt = solve(arr, n, sum, t)
print(cnt)