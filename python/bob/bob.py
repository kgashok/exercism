def hey(input):
    out = None
    input = input.strip()

    if not input:
        out = "Fine. Be that way!"
    elif input.isupper():
        if input[-1] == '?':
            out = "Calm down, I know what I'm doing!"
        else:
            out = "Whoa, chill out!"
    elif input[-1] == '?':
        out = "Sure."
    else:
        out = "Whatever."

    return out
