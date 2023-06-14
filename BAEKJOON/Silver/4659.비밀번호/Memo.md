## 문제 
https://www.acmicpc.net/problem/4659


## 접근 방식
1. for 두 번 쓴 방식
    - while(true) 와 exit()를 사용
    - checkCon[] 배열을 이용해서 따로 자음위치와 모음 위치를 나타내는 배열 생성
        - 3개의 연속적인 모음 or 자음을 확인 하기위해 

2. for 한 번 쓴 방식
    - lcnt , vcnt를 초기화 하는 방식 이용
        - lcnt -> 자음 , vcnt -> 모음
    - prev를 사용 

