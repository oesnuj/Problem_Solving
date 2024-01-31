
#테스트 케이스의 개수를 입력받는다.
T=int(input())

#테스트 케이스만큼 반복한다.
for _ in range(T):
    #연속된 O의 갯수가 있을 경우 증가시킬 변수를 선언한다.
    score=0
    #점수를 구하는 변수를 선언한다.
    sum_score=0
    #테스트 케이스를 입력받는다.
    problem=input()
    for pro in problem:
        #테스트 케이스의 일부가 O일 경우
        if pro=="O":
            #O가 연속될 경우 1씩 추가한다.
            score+=1
            #합을 구한다.
            sum_score+=score
        #X일 경우
        else:
            score=0
    print(sum_score)