N, K, A, B = map(int, input().split())
s = input()
s = s[:N+1]

def findIDX(S, R):
    i = 0
    idx = []
    while i < len(S)-4:
        tmp = S.find(R, i)
        if tmp == -1:
            break
        idx.append(tmp)
        i = tmp + 1
    return idx

def checkIfEqual(letters):
    letter_counts = {}
    for letter in letters:
        if letter in letter_counts:
            letter_counts[letter] += 1
        else:
            letter_counts[letter] = 1
    counts = list(letter_counts.values())
    if all(count == counts[0] for count in counts):
        return True
    else:
        return False
    

def czat(S, k, a, b):
    for i in range(b-N):
        R = ""
        n = k
        
        while n > 0:
            R += S[-n]
            n -= 1

        indexes = findIDX(S, R)
        
        letters = []
        for i in indexes:
            if i+k < len(S):
                letters.append(S[i+k])

        equal = checkIfEqual(letters)
        if equal:
            c = 'a'
        else:
            c = max(set(letters), key=letters.count)

        S += c
        
    print(S[a-1:b])
   
czat(s, K, A, B)
