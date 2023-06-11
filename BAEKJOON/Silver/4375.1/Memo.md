## 문제 
https://www.acmicpc.net/problem/4375

## 접근 방식
1. while(cin >> n)을 사용
    - 11부터 * 10 + 1씩 하는 while문 이용
    - 모듈러 연산을 사용함으로써 시간초과를 해결한다.
        - n이 10000 일 때 Long long 타입도 초과를 한다. 
    - if 문을 통해 해당 숫자가 배수면 자리수 return