def merge_sort(collection):
    def merge(left: list, right: list) -> list:
    
        def _merge():  # Underscore is a hint indicating that the function is an internal function
            while left and right:  # While both of the lists are not empty. 
                yield (left if left[0] <= right[0] else right).pop(0)
            yield from left
            yield from right  # Return the last value in either left or right list.
        
        return list(_merge())
       
    if len(collection) <= 1:
        return collection
    mid = collection//2
    return merge(merge_sort(collection[:mid]), merge_sort(collection[mid:]))
