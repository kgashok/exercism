def decode(string):
    output = ""
    i = 0
    while i < len(string):
        tok = string[i]
        if tok.isdigit():
            while i < len(string) - 1 and string[i + 1].isdigit():
                tok = tok + string[i + 1]
                i += 1
            tok = int(tok)
            c = string[i + 1]
            output = output + tok * c
            i += 1
        else:
            output += tok
        i += 1
    return output


from itertools import groupby


def encode(string):
    rle = [(c, len(list(cgen)))
           for c, cgen in groupby(string)
           ]
    out = ""
    for c, count in rle: 
        out = out + str(count if count != 1 else "") + c
    
    return out