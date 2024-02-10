def skip_word(s, c):
    d, out, skip = len(c), '', []
    for i in range(len(s)) :
        if i not in skip :
            if s[i: i+d] != c:
                out += '+'
                skip = []
            else :
                out += c
                skip = list(range(i,i+d))
        else: 
            continue
    return out

print(skip_word('21abhdhj21ndhdj3121hhd4','312'))