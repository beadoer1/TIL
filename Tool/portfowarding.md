## 포트포워딩(Port Fowarding) 관련 명령어 간략 정리
항해99 주특기 miniproject를 AWS에서 구입한 리눅스 서버에 올리고 포트포워딩을 하는데 연결이 잘 되지 않았다.  
이전에 다른 포트번호로 포트포워딩이 되어있어서 발생한 문제였다.  
간략 명령어들과 현상을 남겨본다.  
※ 이 내용은 항해99 크루인 고성빈님의 [블로그 글](https://seongbindb.tistory.com/128)을 참고하였다.  
  
#### 포트포워딩 등록
**입력 명령어**
```
sudo iptables -t nat -A PREROUTING -i eth0 -p tcp --dport 80 -j REDIRECT --to-port 8080
```

#### 현재 포워딩 되어있는 포트들을 확인.(과거 이력까지)  
**입력 명령어**  
```
~$ sudo iptables -t nat -L
```  
**반환값**  
- 반환값을 보면 제일 상위에 5000번 포트로 포워딩 되어있음을 확인할 수 있다.(내가 필요한 건 8080 포트)  
```
Chain PREROUTING (policy ACCEPT)
target     prot opt source               destination
REDIRECT   tcp  --  anywhere             anywhere             tcp dpt:http redir ports 5000
REDIRECT   tcp  --  anywhere             anywhere             tcp dpt:http redir ports 8080
REDIRECT   tcp  --  anywhere             anywhere             tcp dpt:http redir ports 8080
REDIRECT   tcp  --  anywhere             anywhere             tcp dpt:http redir ports 8080
```

#### 불필요한 포트포워딩 삭제  
**입력 명령어**  
```
sudo iptables -D PREROUTING -t nat -i eth0 -p tcp --dport 80 -j REDIRECT --to-port 5000
```
**다시 조회한 결과**  
- 5000번 포트가 없어진 것을 확인할 수 있다.
```
REDIRECT   tcp  --  anywhere             anywhere             tcp dpt:http redir ports 8080
REDIRECT   tcp  --  anywhere             anywhere             tcp dpt:http redir ports 8080
REDIRECT   tcp  --  anywhere             anywhere             tcp dpt:http redir ports 8080
```

