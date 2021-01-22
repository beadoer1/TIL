## **Hello Coding 그림으로 개념을 이해하는 알고리즘**
**'Hello Coding 그림으로 개념을 이해하는 알고리즘' 책을 보고 자료구조와 알고리즘에 대해 정리하려 합니다.**
- 시작일 : 2021.01.21
- 종료일 :  
※ 다 읽었다고 다 아는 것은 아니다.  

[Ch1. 알고리즘의 소개](#Ch1-알고리즘의-소개)  
[Ch2. 선택 정렬](#Ch2-선택-정렬)  

### **Ch1. 알고리즘의 소개**

**알고리즘**
- 어떤 일을 하기 위한 명령의 집합

**이진 탐색**
- 입력 : **정렬된 원소 리스트**
- 리스트에 원하는 원소가 있으면 그 원소의 위치를 반환하고, 아니면 null 값 반환
- 단순 탐색으로 최대 n번 걸릴 경우 이진 탐색은 최대 log2(n)번 만에 원하는 원소를 찾을 수 있음
※ 단순 탐색은 처음부터 하나씩 원소를 모두 확인하는 것을 의미  
※ log2(n) 은 '2를 몇 번 곱해야 n 이 되는가'를 의미(5 = log2(32)) 여기서 나오는 log n 은 전부 이에 해당

```
# with python
import math

def binary_search(list,item):
    low = 0
    high = len(list) - 1

    while low <= high:
        mid = math.floor((low + high) / 2)
        guess = list[mid]
        
        if guess == item :
            return mid
        elif guess > item :
            high = mid - 1
        else :
            low = mid + 1
    return None

my_list = [1, 3, 5, 7, 8]

print(binary_search(my_list,6)) # None 
print(binary_search(my_list,7)) # 3 index num 3에 위치
```

```
// with java
import java.util.Scanner;

public class binary_search {

	public static void main(String[] args) {

		int[] arr = {1,3,5,7,8,10,11};
		
		int low = 0;
		int high = arr.length - 1;
		System.out.print("찾고자 하는 숫자를 입력하세요.>");
		Scanner scanner = new Scanner(System.in);
		int num =  scanner.nextInt();
		
		while(low <= high) {
			int mid = (low + high)/2;			

			if(arr[mid] == num) {
				System.out.println(num + "이(가) index " + mid +" 에 존재 합니다.");
				break;
			} else if(num > arr[mid]) {
				low = mid + 1;
			} else if(num < arr[mid]) {
				high = mid - 1;
			} 
		}
		
		if (!(low<=high)) {
			System.out.println("해당 숫자는 없습니다.");
		}
	}
}
```

**실행 시간(Running Time)**
- 선형 시간(linear time) : 탐색에 걸리는 최대 횟수가 리스트의 길이와 같은 경우
- 로그 시간(logarithmic time) : 리스트의 길이를 n 이라고 할 때 log(n)에 비례하는 경우

**빅 오 표기법(Big O notation) : O(x)**
- Big O 표기법 : 알고리즘이 얼마나 빠른지 표시하는 방법
- O(x) 형태로 표기 -> x는 연산 횟수로 n개의 리스트가 있을 때 n, log n, n^2 등으로 표기
- 알고리즘의 속도는 시간이 아니라 연산 횟수가 어떻게 증가 하는지로 측정
- 소요될 수 있는 최악의 경우를 괄호 안에 표기
- 많이 사용되는 Big O 예시
	- O(log n) : 로그 시간 ex) 이진 탐색
	- O(n) : 선형 시간 ex) 단순 탐색
	- O(n log n) :  ex) 퀵 정렬과 같이 빠른 정렬 알고리즘
	- O(n^2) : ex) 선택 정렬과 같이 느린 정렬 알고리즘
	- O(n!) : ex) 외판원문제와 같이 정말 느린 알고리즘

### **Ch2. 선택 정렬**

**배열과 연결 리스트**
- 배열(array)을 이용한 목록화
	- 원소를 메모리에 차례대로 붙여서 저장(모든 원소가 이웃하게 됨)
	- 모든 원소의 주소를 알고 있어, 특정 원소를 쉽게 찾을 수 있음
	- 저장 중 공간이 모자른 경우 전체를 수용가능한 새로운 위치로 옮겨야 함	
	- 미리 여분의 메모리를 확보할 경우 쓸데 없이 낭비되는 경우가 생김
	- 원소를 가운데 추가(삽입)하는 경우 다음에 오는 모든 원소의 위치를 바꾸어야 함
- 연결 리스트(linked list)를 이용한 목록화
	- 각 원소에 목록의 다음 원소에 대한 주소를 함께 저장하여 메모리 주소들을 하나의 목록으로 연결
	- 원소를 메모리 어느 곳에나 둘 수 있음
	- 원소를 가운데에 추가(삽입)하는 경우 이전 원소가 무엇을 가리키는지 바꾸기만 하면 되므로 리스트가 유리
	- 원소를 삭제하는 경우에도 위와 같은 이유로 리스트가 유리
	- 이전에 저장한 원소를 옮기거나 할 필요가 없음
	- 특정 원소를 찾기 위해서는 이전 원소들을 모두 따라가봐야 함
- 배열과 리스트에서 읽기와 쓰기 연산을 하는데 걸리는 실행 시간

| 구분  | 배열  | 리스트|
| ----- + ----- + ----- |
| 읽기  | O(1)  | O(n)  |
| 쓰기  | O(n)  | O(1)  |
| 삭제  | O(n)  | O(1)  |
<br/>
※ 실 사용에서는 임의 접근하여 Data를 읽는 경우가 많아 배열을 주로 사용한다.  

**선택 정렬(selection sort)**
- 순서에 맞는 원소를 찾고, 목록에 기록한다.
- O(n^2) : 원소를 찾는데 O(n), 기록하는데 O(n) 하여 O(n)xO(n)=O(n^2) (상수는 무시)

```
# with python
def findSmallest(arr):
    smallest = arr[0]
    smallestIndex = 0

    for i in range(1,len(arr)):
        if arr[i] < smallest:
            smallest = arr[i]
            smallestIndex = i
    return smallestIndex

def selectionSort(arr):
    newArr = []

    for i in range(len(arr)):
        smallest = findSmallest(arr)
        newArr.append(arr.pop(smallest))
    return newArr

print(selectionSort([6,9,1,4,7,2])) # [1, 2, 4, 6, 7, 9]
```
```
// with java

```


