def main(a, res=[]):
    for dict_var in a:  res.append({key:dict_var[key] for key in dict_var if not(bool([dict_var[key] for i in range(2,dict_var[key]) if dict_var[key]%i==0])) })
    return res
print(main([{'a':20,'b':13}, {'c':5,'d':7},{23:13, 64:53}]))
