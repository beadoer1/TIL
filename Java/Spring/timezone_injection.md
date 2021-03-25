## 자바 파일에 timezone 주입하기
Java Spring을 통해 구현한 CRUD 게시판이 EC2서버에서 글을 작성할 때와 로컬서버에서 작성할 때의 작성시간이 다르다..  
해당 글은 [ubuntu 에서 timezone 확인/수정하기](https://github.com/beadoer1/TIL/blob/main/OS/linux/ubuntu_timezone.md)의 연장선으로, timezone을 java 파일에 주입하는 방법에 대해 적어보려 한다.  

### 실행 명령어를 통한 방법
- 보통 `.jar` 파일을 실행하는 명령어는 아래와 같은데,
```
ubuntu@ip-000:~$ java -jar bulletin-0.0.1-SNAPSHOT.jar
```
- 아래와 같이 `-Duser.timezone=대륙/도시`를 넣어주어 실행 시 timezone을 주입할 수 있다.
```
// Asia/Seoul 로 timezone 을 세팅
 ubuntu@ip-000:~$ java -jar -Duser.timezone=Asia/Seoul bulletin-0.0.1-SNAPSHOT.jar
```
- 해당 방법은 매 실행마다 넣어줘야한다는 점에서 한 장소만 나타낼 웹프로그램이라면 불편할 수 있다는 단점을 갖는다.

### Annotation을 통해 Spring에 알리는 방법
- `@SpringBootApplication` Annotation이 부여된 Application Class에 지정한 timezone을 기본설정으로 하는 메서드를 만들고 `@PostConstruct`를 부여한다.
- `@PostConstruct`는 Bean이 완전히 초기화 된 후 단 한번만 호출되는 메서드를 지정하는 것이라고 한다. 그러니까 본격적인 프로세스를 밟기 전 실행하는 것이라고 보면 될 듯 하다.
```
@SpringBootApplication
public class BulletinApplication {
    @PostConstruct // Bean이 완전히 초기화 된 후 단 한번만 호출되는 메서드
    public void started() {
        TimeZone.setDefault(TimeZone.getTimeZone("Asia/Seoul"));
    }
    public static void main(String[] args) {
        SpringApplication.run(BulletinApplication.class, args);
    }
}
```
  
#### ※ 참고자료
- [블로그: 배움이 즐거운 개발자 ']( https://galid1.tistory.com/646)