## 문제 
https://www.acmicpc.net/problem/10808

## 정리
1. 맵 또는 배열을 이용(counting)
    - String 개수와 관련이면 Map 사용, Integer 개수와 관련이면 배열 사용
    - 단 Integer이 단위로 나올 시 map으로 접근 (ex :포인터 단위 -> 1000만 100만 10만 만) 

## 접근 방식
1. 배열
    - 알파벳 소문자를 아스키 코드로 전환 시 97 ~ 122
        - 65 : A , 97 : a
    - 아스키로 전환된 숫자를 index로 생각
    - 각 배열 index에 +1 

