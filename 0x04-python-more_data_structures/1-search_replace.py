#!/usr/bin/python3
def search_replace(my_list, search, replace):
    # Create a new list to store the replaced values
    new_list = []

    # Iterate over each element in the input list
    for element in my_list:
        # If the element matches the search value, replace it with the new value
        if element == search:
            new_list.append(replace)
        else:
            new_list.append(element)

    # Return the new list
    return new_list
