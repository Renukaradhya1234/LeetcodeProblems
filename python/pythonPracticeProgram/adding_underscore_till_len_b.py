def check(a, b):
    out = []
    for i in range(0, len(a), 2):
        count = b - (len(a[i]) + len(a[i+1]))
        out.append((a[i]+('_'*count)+a[i+1]))
    return out
print(check(['python', 'is', 'easy', 'but'], 12))
