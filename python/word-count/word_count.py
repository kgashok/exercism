from collections import Counter
import re

# https://stackoverflow.com/a/1059601/307454 for re.split()


def word_count(phrase):
    wlist = [word.lower()
             for word in re.split('\W+|_', phrase) if len(word)
             ]
    return Counter(wlist)