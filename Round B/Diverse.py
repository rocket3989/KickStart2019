from collections import defaultdict

T = int(input())


for test in range(1,T + 1): 
    
    N, S = list(map(int, input().split()))

    trinkets = list(map(int, input().split()))

    r, l = 0,0

    score = 0

    trinkhash = defaultdict(int)

    while r < N:

        add = True

        for k, v in trinkhash.items():
            if v > S:
                add = False


        if add:
            score = max(score, r - l)
            trinkhash[trinkets[r]] += 1
            r += 1

        else:
            trinkhash[trinkets[l]] -= 1
            if trinkhash[trinkets[l]] == 0:
                del trinkhash[trinkets[l]]
            l += 1
        
        print(trinkhash)
        
    print("Case #{}: {}".format(test,score))