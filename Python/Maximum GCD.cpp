def max_gcd(num):
    m = num
    res = 0
    i = m
    while(i > 0):
        a = i
        cnt = 0
        while (a <= m):
            cnt += 1
            a += i
        if cnt >= 2:
            res = i
            break
        i = i - 1 
    return res

test_case = int(input())
for case in range(test_case):
    num = int(input())
    print(max_gcd(num))
