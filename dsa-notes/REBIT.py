from collections import defaultdict


def power(a,n,m):
    
    res = 1
    
    while n:
        if (n&1):
            res = (res*a)%m
        n //= 2
        a = (a*a)%m
    
    return res
        

def Or(a,b):
    if a.isdigit() and b.isdigit():
        return str( int(a)|int(b) )
    if (not a.isdigit()) and (not b.isdigit()):
        if (a==b):
            return a
        else:
            return "1"
    if (a.isdigit()) and (not b.isdigit()):
        if (a=="0"):
            return b
        if (a=="1"):
            return "1"
    if (b.isdigit()) and (not a.isdigit()):
        if (b=="0"):
            return a
        if (b=="1"):
            return "1"

def And(a,b):
    if a.isdigit() and b.isdigit():
        return str( int(a)&int(b) )
    
    if (not a.isdigit()) and (not b.isdigit()):
        if (a==b):
            return a
        else:
            return "0"
    if (a.isdigit()) and (not b.isdigit()):
        if (a=="0"):
            return "0"
        if (a=="1"):
            return b
    if (b.isdigit()) and (not a.isdigit()):
        if (b=="0"):
            return "0"
        if (b=="1"):
            return a
        
def Xor(a,b):
    if a.isdigit() and b.isdigit():
        return str( int(a)^int(b) )
    
    if (not a.isdigit()) and (not b.isdigit()):
        if (a==b):
            return "0"
        else:
            return "1"
    if (a.isdigit()) and (not b.isdigit()):
        if (a=="0"):
            return b
        if (a=="1"):
            if (b=="a"):
                return "A"
            else:
                return "a"
            
    if (b.isdigit()) and (not a.isdigit()):
        if (b=="0"):
            return a
        if (b=="1"):
            if (a=="a"):
                return "A"
            else:
                return "a"


# def P(o1, o2):
#     """ 
#     return True if precedence of o1 >= o2
#     """
#     if o1 == "&":
#         return True
    
#     if o1 == "^" and (o2=="^" or o2=="|"):
#         return True
    
#     if o1 == "|" and o2 == "|":
#         return True
    
#     return False

def operation(a,b,o):
  #  n1 = ord(a) - ord("0")
  #  n2 = ord(b) - ord("0")
    d = defaultdict(int)
    
    if o == "&":
        for k1,v1 in a.items():
            for k2,v2 in b.items():
                k = And(k1,k2)
                d[k] += v1*v2
    elif o=="^":
        for k1,v1 in a.items():
            for k2,v2 in b.items():
                k = Xor(k1,k2)
                d[k] += v1*v2
    elif o=="|":
        for k1,v1 in a.items():
            for k2,v2 in b.items():
                k = Or(k1,k2)
                d[k] += v1*v2
    
    return d

def solve(x):
    
    S1 = []     #for operand
    S2 = []     #for operator
    
    # for each in x:
    #     if each in ["&", "^", "|"]:
            
    #             while len(S2) and P(S2[len(S2)-1], each):

    #                 a = S1.pop()
    #                 b = S1.pop()
    #                 o = S2.pop()
                
    #                 res = operation(a,b,o)
    #                 S1.append(res)
    #             S2.append(each)
    #     else:
    #         S1.append(each)   
            
    # while len(S2):
    #     a = S1.pop()
    #     b = S1.pop()
    #     o = S2.pop()
        
    #     res = operation(a,b,o)
    #     S1.append(res)
    
    for each in x:
        if each == "(":
            continue
        elif each == ")":
            a = S1.pop()
            b = S1.pop()
            o = S2.pop()
            res = operation(a,b,o)
            S1.append(res)
            
        elif each in ["&","|","^"]:
            S2.append(each)
        else:
            S1.append(each)
    
            
    return S1[0]


def main():
    
    t = int(input())
    for _ in range(t):
        L = list(str(input()))
        
        cnt = 0
        for i in range(len(L)):
            if L[i] == "#":
                cnt += 1
                L[i] = {"0":1, "1":1, "a": 1, "A": 1}
            
        ans = solve(L)
        
        m = 998244353
        
        k = 4**cnt
        temp = power(k,m-2,m)
        for v in ans.values():
            print((v%m * temp)%m, end=" ")
        print()

main()
