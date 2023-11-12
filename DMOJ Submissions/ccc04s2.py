n,k = map(int,input().split(" "))

dict = {}

#information: yodeller:lowest rank, total score, current rank


for i in range(n):
    dict[i+1] = [0,0,0]
for i in range(k):
    round = list(map(int,input().split(" ")))
    tots = []
    for j in range(n):
        score = round[j]
        dict[j+1][1] += score
        tots.append(dict[j+1][1])
    tots.sort(reverse=True)
    for j in range(n):
        ind = tots.index(dict[j+1][1]) +1
        if ind > dict[j+1][0]:
            dict[j+1][0] = ind
        dict[j+1][2] = ind

for i in dict.keys():
    if dict[i][2] == 1:
        print("Yodeller " + str(i) + " is the TopYodeller: score " + str(dict[i][1]) + ", worst rank " + str(dict[i][0]))