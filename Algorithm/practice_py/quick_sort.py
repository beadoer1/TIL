def quicksort(array):
    if len(array) < 2:
        return array
    else:
        pivot = array[0]
        
        less = [i for i in array[1:] if i < pivot]
        
        greater = [i for i in array[1:] if i > pivot]

        return quicksort(less) + [pivot] + quicksort(greater)

arr = [3,9,1,7,6,2,4,5,8]
newArr = quicksort(arr)
print(newArr)