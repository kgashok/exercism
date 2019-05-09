from string import ascii_lowercase as english_alphabet


def is_pangram(string):
    return all(c in string.lower() for c in english_alphabet)