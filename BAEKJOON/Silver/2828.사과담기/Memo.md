## 문제 
https://www.acmicpc.net/problem/2828

## 정리

## 접근 방식
- 바구니 -> vector
    - 알려준 바구니 크기의 vector를 이용
    - vecotr 내 원소 포함 하는지 않하는지 check
        - 값이 없을시 vecotr내 원소값 +1
        - 없을시 vector 내 원소값 -1
    - 값 변경이 일어난만큼 ret에 더해준다.