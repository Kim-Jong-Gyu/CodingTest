## 문제 
https://www.acmicpc.net/problem/9996

## 정리
1. 정규식
    - 사용하는 상황
        - 주어진 문자열이 주어진 규칙에 맞는지 확인할 때
        - 주어진 문자열에서 원하는 패턴의 문자열을 검색할 때
        - 주어진 문자열에서 원하는 패턴의 문자열로 치환할 때
    
    - 형태
        - regex 변수명(해당 패턴)
    
    - 여러 정규 표현식의 문법
        - 디폴트 : ECMAScript
        - grep
        - icase : 대소문자 구분 x
        - optmize : 정규 표현식 성능이 중요할 떄
    
    - 캡쳐 그룹
        - ( )로 원하는 부분을 감싸게 되면 해당 부분에 매칭된 문자열 얻을 수 있음. 
            - ex : std::regex re("[01]{3}-(\\d{3,4})-\\d{4}"); 
        - 매칭 된 객체 -> smatch 변수 이름 (string의 형태로 반환) 
        - cmatch (char 형태로 반환)
    
    - 함수
        - regex_match(문자열 , 정규 표현식 객체) : 전체 문자열이 주어진 정규 표현 패턴에 맞는지 체크
            -  regex_match(문자열, 매칭 저장 객체, 정규 표현식 객체) : 매칭된 객체를 저장함
                -  참고로 regex_match 의 경우 전체 문자열이 매칭이 된 것이기 때문에 첫 번째 결과에 전체 문자열이 나타나게 됩니다. 그 다음으로 () 안에 들어있던 문자열이 나타나게 된다.
                - ex) match[1].str()
        - regex_ search(문자열, 매칭 저장 객체, 정규 표현식 객체) : 문자열에서 원하는 패턴을 검색하는 일
            - 매칭 저장 객체.suffix() : 검색된 패턴 뒤 부터 끝까지에 해당하는 sub_match 객체 리턴 
            <img width="536" alt="스크린샷 2023-05-23 오후 5 39 51" src="https://github.com/Kim-Jong-Gyu/CodingTest/assets/62927374/01d77bfb-06e2-4577-b41c-b1747fec266a">
        - regex_iterator(문자열 시작 iterator, 문자열 끝 iterator, 정규 표현식 객체)
        - regex_replace(문자열, 정규 표현식 객체, 어떠한 패턴으로 바꿀지)

## 접근 방식
1. 패턴 문제임으로 정규식으로 접근
    - 정규 표현식의 특수 문자 사용법을 이용한다.

2. substr을 이용한다.
    - prefix 와 suffix 를 * 기준으로 나눈다.
    - 예외처리 : prefix 사이즈와 suffix사이즈의 합이 문자열 보다 클 경우
        - ex : (ab*ab) -> ab

## 참고 자료
https://modoocode.com/303
http://www.devholic.net/1000238
