N = int(input())
dasom = int(input())
vote = []

for _ in range(N-1):
    vote.append(int(input()))

cnt = 0

while max(vote, default=0) >= dasom:
    dasom += 1
    max_vote = max(vote, default=0)  # 배열에서 최댓값을 찾음
    max_index = vote.index(max_vote)  # 최댓값의 인덱스를 찾음
    vote[max_index] -= 1
    cnt += 1

print(cnt)
