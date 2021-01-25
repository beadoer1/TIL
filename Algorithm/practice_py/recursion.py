def countdown(i):
    print(i)
    if i <= 1: # 기본 단계
        return
    else: # 재귀 단계
        countdown(i-1)

countdown(5)