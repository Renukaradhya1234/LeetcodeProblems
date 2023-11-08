'''
  input: [[1,2,[8,88,66,44,[55,22,33]]], [3,[7,8,[9,6,5,[6,2,5]]]], [[77,33],7,37,273]]
  output: [1, 2, 8, 88, 66, 44, 55, 22, 33, 3, 7, 8, 9, 6, 5, 6, 2, 5, 77, 33, 7, 37, 273]

  Hint: combine all the list to one list
'''

def single(lists, sing=[]):
    if len(lists)==0:
        return []
    for li in lists:
        sing+(single(li)) if type(li)==list else sing.append(li)
    return sing
print(single([[1,2,[8,88,66,44,[55,22,33]]], [3,[7,8,[9,6,5,[6,2,5]]]], [[77,33],7,37,273]]))
