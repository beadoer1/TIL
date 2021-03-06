# Python
Python을 가지고 프로젝트, 알고리즘 풀이 등을 하며 알게되는 사용법에 대해 정리합니다.

### 1. 기초 문법
**주석**
- 주석은 '#'을 사용하여 표기하고 여느 언어와 같이 cmd + '/' 로 처리 가능하다.

**변수 선언**
```
a = 3          # 3을 변수 a에 넣는다.
b = a          # a를 변수 b에 넣는다.
a = a + 1      # a + 1 을 다시 a에 넣는다.

num1 = a * b   # a * b 의 결과값을 num1이라는 변수에 넣는다.
num2 = 99      # 99의 값을 num2라는 변수에 넣는다.
```

**자료형**
- 숫자, 문자
```
name = 'bab'     # string 
num = 12         # 숫자
is_number = True # boolean
```

- List (Javascript 배열과 동일)
```
a_list = []          
a_list.append(1)     # 리스트에 값을 넣는다.
a_list.append([2,3]) # 리스트에 [2,3]이라는 리스트를 다시 넣는다.

# 위 명령어에 대한 출력값(print() 사용하여 출력 필요)
a_list 의 값 : [1,[2,3]]
a_list[0] : 1
a_list[1] : [2,3]
a_list[1][0] : 2
```

- Dictionary (Javascript dictionary 와 동일
```
a_dict = {}
a_dict = {'name':'bob', 'age':21}
a_dict['height'] = 178

# 위 명령어에 대한 출력값(print() 사용하여 출력 필요)
a_dict : {'name':'bob', 'age':21, 'height':178}
a_dict['name'] : 'bob'
a_dict['age'] : 21
a_dict['height'] : 178
```

- Dictionary 와 List 는 조합 가능하다.
```
people = [{'name':'bob', 'age':20},{'name':'carry', 'age':38}]
person = {'name':'john', 'age':7}
people.append(person)

# 위 명령어에 대한 출력값(print() 사용하여 출력 필요)
people[0]['name'] : 'bob'
people[1]['name'] : 'carry'
people : [[{'name':'bob', 'age':20},{'name':'carry', 'age':38},{'name':'john', 'age':7}]
people[2]['name'] : 'john'
```
**조건문**

**반복문**
1. for 반복문
- Python 에서의 for 반복문은 '리스트'의 요소들을 하나씩 꺼내서 쓰는 형태!
```
list_test = [1,2,3]
for index in list_test:
	print(index)
# 출력
1
2
3
```
- 기존에 이해하던 방식으로 사용하고 싶다면 range() 함수와 함께 사용한다.  
	※ range(num) 함수는 0부터 해당 num 미만의 숫자까지 포함하는 range 객체를 만들어 준다.  
```
for i in range(3):
	print(i)
# 출력
0
1
2
```

### 2. 유용한 명령어
**문자열을 한글자씩 list에 담는 list(string)**
```
str = 'Hello World'
print(list(str))  # ['h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd']
```

**map**
- map() 함수는 두번째 인자로 넘어온 데이터가 담고 있는 모든 데이터에 변환 함수를 적용하여 다른 형태의 데이터를 반환한다.
- list 인자에 일괄적으로 특정 명령어를 적용하고 싶을 때 사용하면 좋다.
```
map(변환 함수, 순회 가능한 데이터)

list_test = ['5', '50', '70', '80', '90']
map_test = map(int,list_test)  # map_test 라는 변수에 map(int, list_test)를 처리한 map 객체가 저장됨
print(map_test)
print(list(map_test))

# 출력
<map object at 0x7f9a2bc340a0>
[5, 50, 70, 80, 90]
```

**list에 input() 받기 'map()' 활용**
- 변수에 input().split()을 받으면 list 형태로 저장된다.
```
cl = input().split()
print(cl)

# 입력
5 50 70 80 90
# 출력
['5', '50', '70', '80', '90']
```
- str 을 int 로 바꾸어 출력하려면 아래와 같이 map() 함수를 활용하면 된다.
```
cl = map(int,input().split())
print(cl)           # 만들어진 map 객체의 주소를 반환 
print(list(cl_1))   # list 를 사용하여 list 형태로 반환 가능

# 입력 
50 70 80 20 70
# 출력
<map object at 0x7ff18496b550>
[50, 70, 80, 20, 70]
```

**동적으로 변수 생성,호출하기(for문으로 변수 생성 'locals()','globals()')**
- local() 함수는 현재의 local변수들을 Dictionary 형태로 return 한다.
- globals() 함수는 현재의 global변수들을 Dictionary 형태로 return 한다.
- local변수 global변수는 변수 사용의 허용 범위로 예상하고, 알고리즘 풀이를 위해 알아보는 중이니 사용법을 알아본다.
```
globals()['test'] = 100	# {'test': 100} item 추가
print(globals())
print(globals()['test'])
print('test : ' + test)

# 출력
{앞의 내용은 생략, 'test': 100}
100
test : 100
```
- 이를 활용한 for문으로 변수 생성
```
for i in range(5):
    globals()['test'+str(i)] = 'test'+str(i)
    print(globals()['test'+str(i)])

# 출력
test0
test1
test2
test3
test4
```

**list의 길이를 알려주는 len(list명)**
```
list_a = [1,2,3,4,5,6,7]
len_a = len(a)
print(len_a)

# 출력
7
```

**List의 위치 반환 함수 list명.index(value)**
- index(value) 함수는 리스트에 value 가 있으면 그 위치 값을 돌려준다.
```
a = [1, 2, 3]
print(a.index(3)) # 2
print(a.index(1)) # 0
``` 

### 3. 유용한 모듈
- 기본 내장 모듈이 아니라면 먼저 terminal에 'pip install'을 이용해 설치를 하고,
- 그 후에 'import'를 사용하여 문서에 적용 시킨 후에 사용한다.

**수학에 관련된 'math'**
- math.ceil(i) : 올림
- math.floor(i) : 내림(낮은 방향을 향함)
- math.trunc(i) : 버림(0을 향함 음수의 경우 math.floor()와 다른 값을 가짐)
- math.round(실수,n) : 반올림 (기본적으로 4사5입이 아닌 반올림할 위치 앞자리가 짝수이면 내리고, 홀수이면 올린다.)

**문자열 변경 모듈 'string'**
- string.upper() : 문자열 내부의 '모든' 알파벳을 대문자로 변경한다.
- string.lower() : 문자열 내부의 '모든' 알파벳을 소문자로 변경한다.
- string.isupper() : 문자열 내부에 있는 모든 문자가 대문자인지 검사한다.(bool 반환)
- string.islower() : 문자열 내부에 있는 모든 문자가 소문자인지 검사한다.(bool 반환) 
```
import string # 대소문자 변경을 위한 모듈 import
# 단어 입력
test1 = 'YounHwan'
test2 = 'younhwan'
print('test1')         # test1
print(test1.upper())   # YOUNHWAN
print(test1.lower())   # younhwan
print(test1.isupper()) # False
print(test1.islower()) # False
print('test2')         # test2
print(test2.upper())   # YOUNHWAN
print(test2.lower())   # younhwan
print(test2.isupper()) # False
print(test2.islower()) # True
```

**list, 튜플 등을 조작 가능한 Collections 모듈**
- OrderedDict : 순서를 유지하는 Dictionary
	- popitem(), move_to_end(key) 등의 전용 메서드
```
from collections import OrderedDict
ordered_dict_ = OrderedDict()

ordered_dict_["James"] = 1
ordered_dict_["Branden"] = 2
ordered_dict_["David"] = 3
ordered_dict_["Karsaw"] = 4

print(ordered_dict_)

# 출력
OrderedDict([('James', 1), ('Branden', 2), ('David', 3), ('Karsaw', 4)])
```

- defaultdict() : 존재하지 않는 key에 요청함에 따른 keyerror를 예외처리 할 수 있는 메서드
```
from collections import defaultdict

def number():
    return 100

dict_ = defaultdict(number)
dict_["a"] = 1
dict_["b"] = 2
dict_["c"] = 3
dict_["d"] = 4

print(dict_["f"]) # 100
```

- deque() : 양방향 큐 데이터 유형을 만드는 데 사용되는 메서드
	- deque명.def() 형태로 아래 메서드들을 사용할 수 있다.
	- append(val), appendleft(val), pop(), popleft(), remove(val)
	- rotate(val), extend(list), extendleft(list), count(val), clear() 
```
deque_ = deque([1,2,3,4,5,6])
print(deque_)
# 출력
deque([1,2,3,4,5,6])
```

- **Counter()** : 목록에 있는 '모든 요소'의 개수를 반환해주는 메서드
	- 'key : value' 형태로 '요소 : 개수' 를 반환한다. 
	- count()가 '특정 요소'의 개수를 반환하는 것과 차이가 있다.
```
from collections import Counter

list_ = ['a','a','b','a','b','b','b','d','d','c','d','g','g','g','g','e','e','e','f']

print(Counter(list_))

# 출력
Counter({'b': 4, 'g': 4, 'a': 3, 'd': 3, 'e': 3, 'c': 1, 'f': 1})
```
- **Counter()의 메서드들**
	- clear() : 카운터 객체에서 모든 key-value 쌍을 제거
	- copy() : 카운터 객체의 복사본을 반환
	- get() : 인자로 key를 입력하면 해당 key와 매칭되는 value를 반환
	- items() : key, value 쌍을 튜플 형태로 반환
	- keys() : 카운터 객체의 key들을 반환
	- values() : 카운터 객체의 value, 즉 카운트들을 반환
	- pop(), popitem()
	- pop() : 인자로 key를 반드시 전달해야 하며, key와 매칭되는 value를 반환하고 해당 key, value 쌍을 카운터 객체에서 제거
	- popitem() : 전달하는 인자가 없어야 하며, 가장 뒤의 key, value 쌍을 튜플 형태로 반환하고 해당 쌍을 카운터 객체에서 제거
	- setdefault() : 카운터 객체에 key, value 쌍을 추가할 때 사용할 수 있음 key만 전달하면 카운트 수는 디폴트로 None key와 함께 default=10과 같이 전달하면 key에 해당하는 카운트에 입력한 숫자가 반영됨
	- subtract() : iterable을 전달하면 각 요소의 값을 각각 빼주고 그 결과의 카운트는 마이너스 값을 가질 수도 있음
	- update() : Counter의 값을 갱신하는 메서드. 딕셔너리랑 비슷하지만 입력값을 str로 넣어도 된다.
```
import collections

a = collections.Counter()
print(a)                 # Counter()

a.update("abcdefg")      # string 형태 추가 가능
print(a)                 # Counter({'f': 1, 'e': 1, 'b': 1, 'g': 1, 'c': 1, 'a': 1, 'd': 1})

a.update({'f':3, 'e':2}) # 딕셔너리와 같이 딕셔너리 형태도 추가 가능
print(a)                 # Counter({'f': 4, 'e': 3, 'b': 1, 'g': 1, 'c': 1, 'a': 1, 'd': 1})
```
	- elements() : 입력된 값의 요소들을 list 형태로 풀어 무작위로 반환한다.
```
import collections

c = collections.Counter("Hello Python")
print(list(c.elements()))   # ['n', 'h', 'l', 'l', 't', 'H', 'e', 'o', 'o', ' ', 'y', 'P']
print(sorted(c.elements())) # [' ', 'H', 'P', 'e', 'h', 'l', 'l', 'n', 'o', 'o', 't', 'y']

c2 = collections.Counter(a=4, b=2, c=0, d=-2)
print(sorted(c.elements())) # ['a', 'a', 'a', 'a', 'b', 'b']

```
	- most_common(n) : 입력된 값의 요소들 중 빈도수(frequency)가 높은 순으로 상위 n개를 **리스트(list) 안의 투플(tuple) 형태**로 반환한다.
```
import collections

c2 = collections.Counter('apple, orange, grape') 
print(c2.most_common())  # [('a', 3), ('p', 3), ('e', 3), ('g', 2), (',', 2), ('r', 2), (' ', 2), ('n', 1), ('l', 1), ('o', 1)]
print(c2.most_common(3)) # [('a', 3), ('p', 3), ('e', 3)]
```

- ChainMap : 다른 dictionary을 하나의 데이터 유형으로 결합하는데 사용하는 메서드
```
from collections import ChainMap
dict_1 = {'a':1,'b':2,'c':3}
dict_2 = {'d':4,'e':5,'f':6}
chain_map_ = ChainMap(dict_1,dict_2)

print(chain_map_)                # ChainMap({'a': 1, 'b': 2, 'c': 3}, {'d': 4, 'e': 5, 'f': 6})
print(list(chain_map_.keys()))   # ['d', 'e', 'f', 'a', 'b', 'c']
print(list(chain_map_.values())) # [4, 5, 6, 1, 2, 3]
```

### 4. 그 외 참고사항
- [Python Formatting 참고 문서](https://pyformat.info/)
	- 백준에서 제출에 문제를 겪었어서 추가

**Ascii code 문자로 변경하기**
- chr(ascii)
```
for i in range(65,91):
    print(chr(i))

# 출력
A
B
...
Y
Z
```
