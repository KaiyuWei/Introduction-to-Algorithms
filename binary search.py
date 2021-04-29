def binarySearch(target, sortedLyst):
    """
    :param target:  the value that is going to be looked for in the list
    :param sortedLyst:  the list where we look for the target value. It is sorted in ascending order
    :return: return the location index of the target value if found. Otherwise return -1.
    """
    left = 0  # Right end of the list
    right = len(sortedLyst) - 1  # Left end of the list
    while left <= right:  # To make sure that the list is not fully traversed
        midpoint = (left + right) // 2  # find the mid point
        if target == sortedLyst[midpoint]:  # if we find the target value in the midpoint
            return midpoint
        elif target < sortedLyst[midpoint]:  # If target is smaller, go to the right side
            right = midpoint - 1
        else:  # If the target is larger, go to the left side.
            left = midpoint + 1
    return -1  # If the target is not found, return -1 
