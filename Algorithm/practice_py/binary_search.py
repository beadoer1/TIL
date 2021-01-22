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

print(binary_search(my_list,6)) # 
print(binary_search(my_list,7))