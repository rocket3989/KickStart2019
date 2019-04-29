from collections import defaultdict

T = int(input())


for test in range(1,T + 1): 
    
    N, Q = list(map(int, input().split()))

    stringIn = input()

    correct = 0

    for question in range(Q):
        
        L, R = list(map(int, input().split()))
        
        charCount = defaultdict(int)

        for c in stringIn[L-1:R:]:
            charCount[c] += 1

        odds = 0

        for k, v in charCount.items():
            if v % 2 == 1:
                odds += 1
        
        if odds > 1:
            continue
        
        if odds == 1:
            if (R - L) % 2 == 0:
                correct += 1
            continue
        else:
            if (R - L) % 2 == 1:
                correct += 1
            continue
    print("Case #{}: {}".format(test,correct))