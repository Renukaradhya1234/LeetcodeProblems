class Node():
    def __init__(self, data):
        self.data = data
        self.next = None
class LinkedList():
    def __init__(self):
        self.header = None
    
    # adding items to begining
    def add_begin(self, data):
        new_node = Node(data)
        new_node.next = self.header
        self.header = new_node

    # adding items in middle
    def add_middle(self, index, data):
        new_node = Node(data)
        index_node = self.header
        i = 0
        while i < index-1 and index_node.next is not None:
            index_node = index_node.next
            i+=1
        new_node.next = index_node.next
        index_node.next =  new_node
    
    # adding items to end
    def add_end(self, data):
        new_node = Node(data)
        index_node = self.header
        while index_node.next is not None:
            index_node = index_node.next
        index_node.next = new_node

    # displaying the items
    def display(self):
        index_node = self.header
        while index_node is not None:
            print(index_node.data)
            index_node = index_node.next
    
    # to remove the item using index
    def remove_index(self, index):
        index_node = self.header
        i = -1
        while i < index and index_node.next is not None:
            index_node = index_node.next
            i+=1
        index_node.next = index_node.next.next
    
    # to remove the item using value
    def remove_value(self, value):
        index_node = self.header
        while index_node is not None:
            if index_node.next.data == value:
                index_node.next = index_node.next.next
            index_node = index_node.next
        
    # to update the items
    def update_list(self, value, new_value):
        index_node = self.header
        while index_node is not None:
            if index_node.data == value:
                index_node.data = new_value
            index_node = index_node.next

obj1 = LinkedList()
obj1.add_begin(10)
obj1.add_begin(20)
obj1.add_begin(30)
obj1.add_begin(40)
obj1.add_begin(50)
obj1.add_begin(60)
obj1.add_middle(3, 35)
obj1.add_middle(5, 25)
obj1.add_end(0.5)
obj1.add_end(0.3)
obj1.update_list(0.3, 0.1)
obj1.remove_value(30)
obj1.display()
    