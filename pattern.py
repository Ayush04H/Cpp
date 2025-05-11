'''
* * * *
* * * *
* * * *
* * * *
'''

def solid_square(rows):
    print(f"--- Solid Square ({rows}x{rows}) ---")
    for i in range(rows):      # Outer loop for rows
        for j in range(rows):  # Inner loop for columns
            print("*", end=" ") # Print star and a space, stay on the same line
        print()                # Move to the next line after a row is printed
    print("-" * 20)
n = 4
# Example usage:
solid_square(n)
solid_square(3)


'''
*
* *
* * *
* * * *
'''
def right_triangle_increasing(rows):
    print(f"--- Right-Angled Triangle (Increasing, {rows} rows) ---")
    for i in range(rows):          # Outer loop for rows (0 to rows-1)
        for j in range(i + 1):     # Inner loop: prints i+1 stars
            print("*", end=" ")
        print()
    print("-" * 20)

# Example usage:
right_triangle_increasing(n)
right_triangle_increasing(3)

'''
* * * *
* * *
* *
*
'''

def right_triangle_decreasing(rows):
    print(f"--- Right-Angled Triangle (Decreasing, {rows} rows) ---")
    for i in range(rows):          # Outer loop for rows (0 to rows-1)
        for j in range(rows - i):  # Inner loop: prints rows-i stars
            print("*", end=" ")
        print()
    print("-" * 20)

# Example usage:
right_triangle_decreasing(n)
right_triangle_decreasing(3)


'''
...*
..**
.***
****
'''
def inverted_right_triangle(rows):
    print(f"--- Inverted Right-Angled Triangle ({rows} rows) ---")
    for i in range(rows):         # Outer loop for rows (0 to rows-1)
        # Print spaces
        for j in range(rows - 1 - i): # Prints (rows-1-i) spaces
            print(" ", end=" ")
        # Print stars
        for k in range(i + 1):        # Prints (i+1) stars
            print("*", end=" ")
        print()
    print("-" * 20)

# Example usage:
inverted_right_triangle(n)
inverted_right_triangle(3)

'''
   *
  ***
 *****
*******
'''
def pyramid(rows):
    print(f"--- Pyramid ({rows} rows) ---")
    for i in range(rows): # Outer loop for rows (0 to rows-1)
        # Print leading spaces
        for j in range(rows - 1 - i):
            print(" ", end="") # Note: single space for denser pyramid look
        # Print stars
        for k in range(2 * i + 1):
            print("*", end="")
        print()
    print("-" * 20)

# Example usage:
pyramid(n)
pyramid(3)


'''
1
1 2
1 2 3
1 2 3 4
'''
def number_triangle_increasing(rows):
    print(f"--- Number Triangle (Increasing, {rows} rows) ---")
    for i in range(rows):          # Outer loop for rows (0 to rows-1)
        for j in range(i + 1):     # Inner loop: numbers from 0 to i
            print(j + 1, end=" ")  # Print j+1 to get 1-based numbers
        print()
    print("-" * 20)

# Example usage:
number_triangle_increasing(n)
number_triangle_increasing(3)

'''
1
2 2
3 3 3
4 4 4 4
'''
def number_triangle_same_num(rows):
    print(f"--- Number Triangle (Same Number, {rows} rows) ---")
    for i in range(rows):          # Outer loop for rows (0 to rows-1)
        for j in range(i + 1):     # Inner loop: repeats i+1 times
            print(i + 1, end=" ")  # Print i+1 (the current row number, 1-based)
        print()
    print("-" * 20)

# Example usage:
number_triangle_same_num(n)
number_triangle_same_num(3)

'''
* * * * *
*       *
*       *
*       *
* * * * *
'''

def hollow_square(size):
    print(f"--- Hollow Square ({size}x{size}) ---")
    for i in range(size):      # Outer loop for rows
        for j in range(size):  # Inner loop for columns
            # Condition to print a star:
            # - First row (i == 0)
            # - Last row (i == size - 1)
            # - First column (j == 0)
            # - Last column (j == size - 1)
            if i == 0 or i == size - 1 or j == 0 or j == size - 1:
                print("*", end=" ")
            else:
                print(" ", end=" ") # Print a space for the hollow part
        print()
    print("-" * 20)

# Example usage:
hollow_square(n)
hollow_square(3) # A 3x3 hollow square is almost solid
hollow_square(6)

'''
1
2 3
4 5 6
7 8 9 10
'''

def floyds_triangle(rows):
    print(f"--- Floyd's Triangle ({rows} rows) ---")
    number = 1
    for i in range(1, rows + 1):  # Outer loop for rows (1 to rows)
        for j in range(1, i + 1): # Inner loop for columns
            print(number, end=" ")
            number += 1
        print()
    print("-" * 30)

# Example usage:
floyds_triangle(n)
floyds_triangle(3)


'''
1 2 3 4
1 2 3
1 2
1
'''
def num_triangle_inverted_increasing_in_row(rows):
    print(f"--- Number Triangle: Inverted, Increasing in Row ({rows} rows) ---")
    for i in range(rows, 0, -1): # Outer loop for rows (rows down to 1)
        for j in range(1, i + 1):  # Inner loop: 1 to current 'i'
            print(j, end=" ")
        print()
    print("-" * 30)

# Example usage:
num_triangle_inverted_increasing_in_row(n)
num_triangle_inverted_increasing_in_row(3)


'''
4 4 4 4
3 3 3
2 2
1
'''

def num_triangle_inverted_same_as_length(rows):
    print(f"--- Number Triangle: Inverted, Same as Length ({rows} rows) ---")
    for i in range(rows, 0, -1):  # Outer loop for rows (rows down to 1)
                                  # 'i' is also the number to print and count of prints
        for j in range(i):        # Inner loop: iterates 'i' times
            print(i, end=" ")
        print()
    print("-" * 30)

# Example usage:
num_triangle_inverted_same_as_length(n)
num_triangle_inverted_same_as_length(3)


'''
      1
    1 2
  1 2 3
1 2 3 4
'''
def num_triangle_right_aligned_increasing(rows):
    print(f"--- Number Triangle: Right-Aligned Increasing ({rows} rows) ---")
    for i in range(1, rows + 1):    # Outer loop for rows (1 to rows)
        # Print spaces
        for k in range(rows - i):   # Prints (rows-i) spaces
            print(" ", end=" ")     # Two spaces for better alignment with two-digit numbers
        # Print numbers
        for j in range(1, i + 1):   # Prints numbers from 1 to i
            print(j, end=" ")
        print()
    print("-" * 30)

# Example usage:
num_triangle_right_aligned_increasing(n)
num_triangle_right_aligned_increasing(3)

'''
      1
    2 2
  3 3 3
4 4 4 4
'''
def num_triangle_right_aligned_same_num(rows):
    print(f"--- Number Triangle: Right-Aligned Same Number ({rows} rows) ---")
    for i in range(1, rows + 1):    # Outer loop for rows (1 to rows)
        # Print spaces
        for k in range(rows - i):
            print(" ", end=" ")
        # Print numbers
        for j in range(1, i + 1):
            print(i, end=" ")       # Print current row number 'i'
        print()
    print("-" * 30)

# Example usage:
num_triangle_right_aligned_same_num(n)
num_triangle_right_aligned_same_num(3)


'''
* * * * * *
*         *
*         *
* * * * * *
'''
def hollow_rectangle(height, width):
    print(f"--- Hollow Rectangle ({height}x{width}) ---")
    if height <= 0 or width <= 0:
        print("Height and width must be positive.")
        return
    for i in range(height):    # Outer loop for rows
        for j in range(width): # Inner loop for columns
            if i == 0 or i == height - 1 or j == 0 or j == width - 1:
                print("*", end=" ")
            else:
                print(" ", end=" ")
        print()
    print("-" * 20)

# Example usage:
hollow_rectangle(4, 6)
hollow_rectangle(n, n + 2)
hollow_rectangle(2, 5) # Will look solid on the inside if height is 1 or 2

'''
*
* *
*   *
*     *
* * * * *
'''

def hollow_right_triangle_increasing(rows):
    print(f"--- Hollow Right-Angled Triangle (Increasing, {rows} rows) ---")
    if rows <= 0:
        print("Rows must be positive.")
        return
    for i in range(rows):      # Outer loop for rows (0 to rows-1)
        for j in range(i + 1): # Inner loop for columns (0 to i)
            # Print '*' if it's the first column, the diagonal, or the last row
            if j == 0 or j == i or i == rows - 1:
                print("*", end=" ")
            else:
                print(" ", end=" ")
        print()
    print("-" * 20)

# Example usage:
hollow_right_triangle_increasing(n)
hollow_right_triangle_increasing(3)
hollow_right_triangle_increasing(1) # Single star
hollow_right_triangle_increasing(2) # Solid triangle


'''
* * * * *
*     *
*   *
* *
*
'''

def hollow_inverted_right_triangle(rows):
    print(f"--- Hollow Inverted Right-Angled Triangle ({rows} rows) ---")
    if rows <= 0:
        print("Rows must be positive.")
        return
    for i in range(rows):          # Outer loop for rows (0 to rows-1)
        for j in range(rows - i):  # Inner loop for columns (0 to rows-1-i)
            # Print '*' if it's the first row, first column, or the diagonal
            if i == 0 or j == 0 or j == (rows - 1 - i):
                print("*", end=" ")
            else:
                print(" ", end=" ")
        print()
    print("-" * 20)

# Example usage:
hollow_inverted_right_triangle(n)
hollow_inverted_right_triangle(3)



'''
    *
   * *
  *   *
 *     *
* * * * *
'''

def hollow_pyramid(rows):
    print(f"--- Hollow Pyramid ({rows} rows) ---")
    if rows <= 0:
        print("Rows must be positive.")
        return
    for i in range(rows):  # Outer loop for rows (0 to rows-1)
        # Print leading spaces
        for k in range(rows - 1 - i):
            print(" ", end="") # Single space for leading space

        # Print stars and inner spaces
        for j in range(2 * i + 1): # Total characters in this part of the row
            # Print '*' if it's the first char, last char in this segment, or the last row
            if j == 0 or j == 2 * i or i == rows - 1:
                print("*", end="")
            else:
                print(" ", end="") # Single space for inner hollow part
        print()
    print("-" * 20)

# Example usage:
hollow_pyramid(n)
hollow_pyramid(3)
hollow_pyramid(1)

'''
* * * * *
 *     *
  *   *
   * *
    *
'''

def hollow_inverted_pyramid(rows):
    print(f"--- Hollow Inverted Pyramid ({rows} rows) ---")
    if rows <= 0:
        print("Rows must be positive.")
        return
    for i in range(rows -1, -1, -1): # Outer loop for rows (rows-1 down to 0)
        # Print leading spaces
        for k in range(rows - 1 - i):
            print(" ", end="")

        # Print stars and inner spaces
        for j in range(2 * i + 1):
            if j == 0 or j == 2 * i or i == rows - 1: # First char, last char, or (original) top row
                print("*", end="")
            else:
                print(" ", end="")
        print()
    print("-" * 20)

# Example usage:
hollow_inverted_pyramid(n)
hollow_inverted_pyramid(3)


'''
    *
   * *
  *   *
 *     *
* * * * *  <- Middle row (n-th row of top half)
 *     *
  *   *
   * *
    *
'''

def hollow_diamond(rows_half): # rows_half is the number of rows for the top pyramid part
    print(f"--- Hollow Diamond (Mid-width has {2*rows_half-1} stars) ---")
    if rows_half <= 0:
        print("Rows for half-diamond must be positive.")
        return

    # Upper part (Hollow Pyramid)
    for i in range(rows_half):
        for k in range(rows_half - 1 - i):
            print(" ", end="")
        for j in range(2 * i + 1):
            if j == 0 or j == 2 * i: # Only edges for non-last row
                print("*", end="")
            elif i == rows_half -1 : # Full last row of pyramid
                print("*", end="")
            else:
                print(" ", end="")
        print()

    # Lower part (Hollow Inverted Pyramid, excluding its first row which is pyramid's last)
    for i in range(rows_half - 2, -1, -1): # Start from rows_half-2
        for k in range(rows_half - 1 - i):
            print(" ", end="")
        for j in range(2 * i + 1):
            if j == 0 or j == 2 * i: # Only edges
                print("*", end="")
            else:
                print(" ", end="")
        print()
    print("-" * 20)

# Example usage:
hollow_diamond(n) # n=5 means top pyramid has 5 rows
hollow_diamond(3)
hollow_diamond(1) # Single star


'''
    *
   * *
  *   *
 *     *
*       *  <- Widest row, also hollow
 *     *
  *   *
   * *
    *
'''


def hollow_diamond_no_solid_middle(rows_in_half):
    print(f"--- Hollow Diamond (No Solid Middle, Top Half has {rows_in_half} rows) ---")
    if rows_in_half <= 0:
        print("Rows for half-diamond must be positive.")
        print("-" * 30)
        return
    if rows_in_half == 1: # Special case for a single star diamond
        print("*")
        print("-" * 30)
        return

    # Upper part (including the widest middle, now hollow)
    # i represents the current row number (0-indexed) in this half
    for i in range(rows_in_half):
        # 1. Print leading spaces
        # For row i, there are (rows_in_half - 1 - i) leading spaces.
        for _ in range(rows_in_half - 1 - i):
            print(" ", end="")

        # 2. Print the hollow row content
        # The content part (stars and inner spaces) has a width of (2*i + 1) characters.
        # Example: i=0: "*", width 1
        #          i=1: "* *", width 3
        #          i=2: "*   *", width 5
        for j in range(2 * i + 1):
            # Print a star if it's the first (j=0) or the last (j=2*i) position of this content segment
            if j == 0 or j == (2 * i):
                print("*", end="")
            else:
                print(" ", end="") # Inner space
        print() # Newline after the row

    # Lower part (inverted pyramid, excluding its first row which was the widest row already printed)
    # i iterates from (rows_in_half - 2) down to 0.
    # This is because the row (rows_in_half - 1) was the widest and already handled by the upper loop.
    for i in range(rows_in_half - 2, -1, -1):
        # 1. Print leading spaces (same logic as upper part)
        for _ in range(rows_in_half - 1 - i):
            print(" ", end="")

        # 2. Print the hollow row content (same logic as upper part)
        for j in range(2 * i + 1):
            if j == 0 or j == (2 * i):
                print("*", end="")
            else:
                print(" ", end="")
        print() # Newline
    print("-" * 30)

# Example usage:
n_half = 5
hollow_diamond_no_solid_middle(n_half)

hollow_diamond_no_solid_middle(3)

hollow_diamond_no_solid_middle(1) # Should print just a single star

hollow_diamond_no_solid_middle(0) # Should print error and return