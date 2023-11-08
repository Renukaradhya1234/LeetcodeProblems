def main(list_var, out=[]):
    for i in list_var:  out.append(sum(list(map(int,list(str(i)))))) if type(i)==int else out.append(sum(list(map(lambda alpha: ord(alpha), i)))) if type(i)==str else True
    return out
print(main([10,'abc',32,5+5j]))
