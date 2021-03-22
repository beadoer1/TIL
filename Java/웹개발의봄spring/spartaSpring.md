# **웹 개발의 봄, Spring**
**스파르타 코딩클럽 '웹 개발의 봄, Spring' 강좌를 보며 정리해 봅니다.**

### **IntelliJ**
**단축키**
- 코드 정렬 : option + command + L
- 임포트 : option + Enter
- 주석 : command + /
- System.out.print() : sout 치고 tab
- 환경설정 : command + ,

### **웹의 기본 개념**
**클라이언트와 서버**
- 클라이언트 : 사용자가 보는 화면. 정확히는 웹사이트로 따졌을 때, 웹 브라우저. 스마트 폰의 경우 어플리케이션 자체에 해당한다.
- 서버 : 클라이언트에서 요청하는 데이터를 가지고 있고, 이 자료들에 대한 클라이언트에 요청에 대해 응답해 주는 곳.

**API(Application Programming Interface)**
-  운영체제와 응용프로그램 사이의 통신에 사용되는 언어나 메시지 형식을 말한다 (두산백과)
- 은행창구 등에 많이 비유한다. 서버와 클라이언트 즉, 응답자와 요청자 간에 소통을 위한 방법 정도로 정리하면 될 것 같다. ET와 교감하기 위해서는 손가락을 내밀어야한다.. 랄까

**HTML,CSS,Javascript**
- 클라이언트에 띄워져 사용자가 눈으로 보는 부분들을 구현하는 언어들

**JSON(JavaScript Object Notation) 형식**
-  "키-값 쌍"으로 이루어진 데이터 오브젝트를 전달하기 위해 인간이 읽을 수 있는 텍스트를 사용하는 **개방형 표준 포맷**이다. (위키백과)
- 'key-value 형태로 이루어진 객체 자료를 전달하는 약속된 양식'이라고 생각하자.
- 확장자는 `.json`
```
한 사람의 정보를 담은 JSON 객체(object)
 {
    "이름": "홍길동",
    "나이": 25,
    "성별": "여",
    "주소": "서울특별시 양천구 목동",
    "특기": ["농구", "도술"],
    "가족관계": {"#": 2, "아버지": "홍판서", "어머니": "춘섬"},
    "회사": "경기 수원시 팔달구 우만동"
 }
```

### **자바 기초 문법**
**화면에 출력**
- System.out.print() : 줄 바꿈 없이 출력
- System.out.println() : 출력 후 줄바꿈

**변수 & 기초 문법**
- 변수는 '값을 담는 상자'
- 변수의 선언 : (자료의 종류)(변수명) = (값)
- 변수명 : 일반적으로 1)영어, 2)소문자 시작,3)구분은 대문자(python의 아랫첨자)
- 항상 코드 작성 후 줄 마지막에 세미콜론(;)을 넣어준다.

**기본형 변수 - boolean, char, byte, short, int, long, float, double**
- 논리형 : boolean (참, 거짓)
- 문자형 : char (문자 하나)
- 정수형 : short, int, long (short는 잘 안쓰임)
- 실수형 : float, double 
- 자세한 건 [자바의 정석 기초편 정리](Java/자바의정석1/자바의정석_남궁성.md) 참고할 것

**참조형 변수(Reference type)**
- 기본형을 제외한 나머지(String, System 등)
- 메모리 주소를 저장(4byte or 8byte)
- 참조 변수는 '객체의 주소를 저장'

**배열-List**
- 순서가 중요한 녀석이다.
- **같은 자료형**만 넣을 수 있다.
- 넣을 때는 add, 조회할 때는 get, 제거할 때는 remove
```
package com.sparta.week01.prac;

import java.util.ArrayList;
import java.util.List;

public class Prac{
    public static void main(String[] args) {
        List<String> myList = new ArrayList<>();
        String course1 = "웹 개발의 봄 Spring";
        String course2 = "프론트엔드의 꽃 React";
        myList.add(course1);
        myList.add(course2);
        System.out.println(myList); // [웹 개발의 봄 Spring, 프론트엔드의 꽃 React
        System.out.println(myList.get(1)); // 프론트엔드의 꽃 React
        myList.remove(1);
        System.out.println(myList); // [웹 개발의 봄 Spring]
    }
}
```

**메서드(Method)**
- 일반적으로 부르는 함수와 거의 동일한 기능
	- 메서드 : 클래스 안에 있음
	- 함수 : 클래스에 독립적이다.
```
// 메서드 사용 형태
public (반환타입) 메소드명(파라미터) {
	// 명령 내용
	return (반환값)
}
```

**반복문과 조건문**
- 반복문 : 반복되는 명령을 수행할 때 사용
```
for (시작조건; 계속하는조건; 더하기) {
	명령
}
```
- 조건문 : 특정 경우에 명령을 수행할 때 사용
```
if (조건) {
	명령
} else if (조건2){
	명령
} else {
 	위 조건 외 상황에서의 명령
}
```

### **자바 클래스**
**객체 지향 프로그래밍(Object Oriented Programming)**
- 프로그래밍을 현실 세계에 빗대어 체계적으로 해보자는 발상에서 나온 프로그래밍 기법

**클래스**
- 클래스는 정보를 묶는 것.
- 현실과 비슷한 개념(객체)을 **나타내기 위한 자바의 도구**를 클래스라고 부른다.
- 클래스 내 정보를 멤버 변수 라고 한다.

**생성자(Constructor)**
- 클래스명과 똑같은 이름을 가진 메서드.
- 객체를 선언할 때 사용하며, 변수에 특정값을 부여할 수도 있다.

### **Getter, Setter**


