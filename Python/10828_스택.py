# python으로 자료구조를 구현하는 방식을 참고하기 위해 wjdtmdgml님 블로그 참고
# input() 함수를 사용하며 시간초과가 되므로 시간 단축을 위해 sys.stdin.readline()함수를 사용
# 입출력 속도 비교 : sys.stdin.readline > raw_input() > input() 
import sys 
N = int(sys.stdin.readline())

stack = []
for i in range(N):
    command = sys.stdin.readline().split()

    if command[0] == 'push':
        stack.append(command[1])
    elif command[0] == 'pop':
        if len(stack) == 0 :
            print(-1)
        else :
            print(stack.pop())
    elif command[0] == 'size':
        print(len(stack))
    elif command[0] == 'empty':
        if len(stack) ==0 :
            print(1)
        else:
            print(0)
    elif command[0] == 'top':
        if len(stack) ==0 :
            print(-1)
        else:
            print(stack[-1])
