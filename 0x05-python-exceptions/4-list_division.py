#!/usr/bin/python3
def list_division(my_list_1, my_list_2, list_length):
    result = []
    for i in range(list_length):
        try:
            elem_1 = my_list_1[i] if i < len(my_list_1) else 0
            elem_2 = my_list_2[i] if i < len(my_list_2) else 0

            # Check if both elements are numbers
            if not isinstance(elem_1, (int, float)) or not isinstance(elem_2, (int, float)):
                raise TypeError("wrong type")

            # Check if division by zero
            if elem_2 == 0:
                raise ZeroDivisionError("division by 0")

            # Perform division and append the result
            result.append(elem_1 / elem_2)

        except ZeroDivisionError:
            print("division by 0")
            result.append(0)

        except TypeError:
            print("wrong type")
            result.append(0)

        except IndexError:
            print("out of range")
            result.append(0)

    return result
