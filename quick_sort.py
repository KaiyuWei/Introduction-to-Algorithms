def quick_sort(collection: list) -> list:
    # Input a list and return a list that is sorted by quick sort.
    if len(collection) < 2:
        return collection
    pivot = collection.pop() #use the last element as the first pivot
    greater :list[int] = [] # All elements that are greater than the pivot
    less: list[int] = [] # All elements that are less than the pivot
    for element in collection:
        (greater if element > pivot else less).append(element)
    return quick_sort(less) + [pivot] + quick_sort(greater)

lst = [1,35,6,7,8,4,76,45,3,6,3,5,]
sorted = quick_sort(lst)
print(sorted)
