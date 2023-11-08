def main(st):
    l=st.split()
    return {i:l[-(l.index(i)+1)] for i in l}
print(main('ee sala cup nmade'))
