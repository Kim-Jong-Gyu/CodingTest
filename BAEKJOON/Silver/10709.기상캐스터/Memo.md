## 문제 
https://www.acmicpc.net/problem/10709

## 정리
1. 증감연산자 후위 전위 
    ''' int cnt = 1;
		while(a[i][j + 1] == -1){
			a[i][j + 1] = cnt++;
        }
    '''
    - a[i][j + 1] 처음 값에는 cnt 1이 들어가고 그 후 1증가
    - 전위일때는 cnt 2값이 들어간다. 
## 접근 방식
1. 이차원 배열 이용