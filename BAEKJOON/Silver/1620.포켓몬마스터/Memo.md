## 문제 
https://www.acmicpc.net/problem/1620

## 접근 방식
1. unordered_map과 배열을 이용한다(두개의 자료구조를 사용).
    - key에 string value에 int
    - if문을 통한 입력값이 숫자인지 문자인지 확인(atoi 사용)
    - 숫자 경우의 수를 위해 배열 하나 생성