"""Pangram Checker
This module provides for function to check for pangram
"""

from string import ascii_lowercase as english_alphabet


def is_pangram(text):
    '''
    >>> is_pangram("abcde")
    False
    >>> is_pangram("a lazy brown fox quickly jumped over the green fence")
    True
    '''

    alphabet = set(english_alphabet)
    text = set(text.lower())
    return alphabet.issubset(text)
