"""Pangram Checker
This module provides for function to check for pangram
"""

from string import ascii_lowercase as alphabets


def is_pangram(text):
    '''
    >>> is_pangram("abcde")
    False
    >>> is_pangram("a lazy brown fox quickly jumped over the green fence")
    True
    '''

    return set(alphabets).issubset(text.lower())
