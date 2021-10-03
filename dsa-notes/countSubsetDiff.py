def solve(arr, n, sum, t):
    if t[n][sum] != None:
        return t[n][sum]
    elif n==0 and sum != 0:
        t[n][sum] = 0
        return t[n][sum]
    elif sum == 0:
        t[n][sum] = 1
        return t[n][sum]
    elif arr[n-1] <= sum:
        t[n][sum] = solve(arr, n-1, sum-arr[n-1], t) + solve(arr, n-1, sum, t)
        return t[n][sum]
    elif arr[n-1] > sum:
        t[n][sum] = solve(arr, n-1, sum, t)
        return t[n][sum]

arr = [1,2,2,3]
diff = 2
n = len(arr)
if (diff + sum(arr))%2 != 0:
    print(0)
else:
    s1 = (diff + sum(arr))//2
    t = [[None]*(s1+1) for _ in range(n+1)]
    solve(arr, n, s1, t)
    print(t[n][s1])