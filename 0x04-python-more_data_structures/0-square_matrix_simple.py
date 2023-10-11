#!/usr/bin/python3
def square_matrix_simple(matrix):
    # Create a new matrix to store the squared values
    new_matrix = []

    # Iterate over each row in the input matrix
    for row in matrix:
        # Create a new row to store the squared values of the current row
        new_row = []
        # Iterate over each element in the current row
        for element in row:
            # Compute the square of the element and append it to the new row
            new_row.append(element ** 2)
        # Append the new row to the new matrix
        new_matrix.append(new_row)

    # Return the new matrix
    return new_matrix
