def solve(arr, n, sum, t):
    for i in range(n+1):
        for j in range(sum+1):
            if i==0 and j != 0:
                t[i][j] = False
            elif j == 0:
                t[i][j] = True
        
    for i in range(1, n+1):
        for j in range(1, sum+1):
            if arr[i-1] <= j:
                t[i][j] = t[i-1][j-arr[i-1]] or t[i-1][j]
            elif arr[i-1] > j:
                t[i][j] = t[i-1][j]

arr = [2,3,5,6,8,10]
sum = sum(arr)
n = len(arr)
t = [[None]*(sum+1) for _ in range(n+1)]
solve(arr, n, sum, t)
v = []
for i in range(len(t[n])//2+1):
    if t[n][i]:
        v.append(i)
print(sum - 2*v[-1])