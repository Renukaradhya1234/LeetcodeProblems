class add_set:
    def __init__(self,a):
        self.a=a
    def __add__(self,other):
        out=self.a
        for i in other.a:
            out.add(i)
        return out
s1=add_set({1,2,3})
s2=add_set({2,3,4})
print(s1+s2)
