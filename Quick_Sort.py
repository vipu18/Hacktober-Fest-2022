"""
Divide the collection in two (roughly) equal parts by taking a pseudo-random element and using it as a pivot.
Elements smaller than the pivot get moved to the left of the pivot, and elements larger than the pivot to the right of it.
This process is repeated for the collection to the left of the pivot, as well as for the array of elements to the right of the pivot until the whole array is sorted.
"""

def partition(array, start, end, compare_func):
    pivot = array[start]
    low = start + 1
    high = end

    while True:
        while low <= high and compare_func(array[high], pivot):
            high = high - 1

        while low <= high and not compare_func(array[low], pivot):
            low = low + 1

        if low <= high:
            array[low], array[high] = array[high], array[low]
        else:
            break

    array[start], array[high] = array[high], array[start]

    return high
  
def quick_sort(array, start, end, compare_func):
    if start >= end:
        return

    p = partition(array, start, end, compare_func)
    quick_sort(array, start, p-1, compare_func)
    quick_sort(array, p+1, end, compare_func)
    
p1 = Person("Dave", 21)
p2 = Person("Jane", 58)
p3 = Person("Matthew", 43)
p4 = Person("Mike", 21)
p5 = Person("Tim", 10)

array = [p1,p2,p3,p4,p5]
quick_sort(array, 0, len(array) - 1, lambda x, y: x.age < y.age)
for person in array:
    print(person)
