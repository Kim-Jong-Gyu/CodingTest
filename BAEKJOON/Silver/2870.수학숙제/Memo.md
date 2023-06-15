## 문제 
https://www.acmicpc.net/problem/2870

## 정리
1. 문자열에 비교연산자를 정렬할려면 custom operator가 필요
    - 문자열일 떄 비교연산자를 사용하면 차근차근 순서대로 하기 때문에 사이즈를 체크 한 후 비교해야한다. 
2. front 같이 위치 참조 함수일 경우 size랑 같이 판단해줘야 한다. 

## 접근 방식
1. 아스키 코드 이용
    - 사이즈가 100글자 이상인 경우 string으로 판단
    - while문과 string:: erase() 함수와 begin 함수를 이용해 숫자 앞 '0' 제거