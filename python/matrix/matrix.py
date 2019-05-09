class Matrix (object):
    def __init__(self, s):
        self.rows = [
            [int(c) for c in row.split()
             ] for row in s.split("\n")
        ]

    @property
    def columns(self):
        return [list(tup) for tup in zip(*self.rows)]


'''
# Matrix

Write a program that, given a string representing a matrix of numbers, can return the rows and columns of that matrix.

So given a string with embedded newlines like:

> 9 8 7
> 5 3 2
> 6 6 7

representing this matrix:

plain
    0  1  2
  |---------
0 | 9  8  7
1 | 5  3  2
2 | 6  6  7


your code should be able to spit out:

- A list of the rows,
  reading each row left-to-right while moving top-to-bottom across the rows,
- A list of the columns,
  reading each column top-to-bottom while moving from left-to-right.

The rows for our example matrix:

- 9, 8, 7
- 5, 3, 2
- 6, 6, 7

And its columns:

- 9, 5, 6
- 8, 3, 6
- 7, 2, 7

def test_extract_a_row(self):
        matrix = Matrix("1 2\n10 20")
        self.assertEqual([1, 2], matrix.rows[0])

## Source

Warmup to the `saddle-points` warmup. [view source](http://jumpstartlab.com)
'''