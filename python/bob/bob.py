def hey(remark):

    out = None
    remark = remark.strip()

    if not remark:
        out = "Fine. Be that way!"
    elif remark.isupper():
        out = "Whoa, chill out!"
    elif remark[-1] == '?':
        out = "Sure."
    else:
        out = "Whatever."

    return out
