from collections import defaultdict

T = int(input())


for test in range(1,T + 1): 
    
    N, S = list(map(int, input().split()))

    trinkets = list(map(int, input().split()))

    r, l = 0,0

    score = 0

    trinkhash = defaultdict(int)

    while r <= N:

        while len(trinkhash) <= S:
            score = max(score, r - l)
            trinkhash[r] += 1
            r += 1
            if r > N:
                break

        while len(trinkhash) > S:
            trinkhash[l] -= 1
            if trinkhash[l] == 0:
                del trinkhash[l]
            l += 1
        
    print("Case #{}: {}".format(test,score))