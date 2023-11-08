def check(st):
    d={'(':')','{':'}', '[':']'}
    open=[]
    for i in st:
        if i in '({[':
            open.append(i)
        else:
            if len(open)==0 or d[open.pop()]!=i:
                return False
    if len(open)!=0:
        return False
    return True
