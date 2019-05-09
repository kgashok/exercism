def is_isogram(string):
    string = string.lower()
    string = "".join([tok for tok in string if tok.isalpha()])
    
    return len(set(string)) == len(string)