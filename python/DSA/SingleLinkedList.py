class Node:
    def __init__(self, data):
        self.prev = None
        self.data = data
        self.next = None

class DoubleLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    
    # to add value to beginning
    def add_begin(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.head.prev = new_node
            new_node.next = self.head
            self.head = new_node
    
    # to add value in middle
    def add_middle(self, index, data):
        new_node = Node(data)
    
    # to add value to last
    def add_end(self, data):
        new_node = Node(data)
        self.tail.next = new_node
        new_node.prev = self.tail
        self.tail = new_node

    # to display the value
    def display(self, index = 0):
        if index >= 0:
            index_node = self.head
            while index_node is not None:
                print(index_node.data)
                index_node = index_node.next
        else:
            index_node = self.tail
            while index_node is not None:
                print(index_node.data)
                index_node = index_node.prev

    # to update the value 
    def update(self, data, new_data):
        index_node = self.head
        while index_node is not None:
            if index_node.data == data:
                index_node.data = new_data
            index_node = index_node.next
    
    # to remove the value by index
    def remove_index(self, index = 0):
        if index >= 0:
            if index == 0:
                self.head = self.head.next
            else:
                i = 0
                index_node = self.head
                while i < index and index_node.next is not None:
                    index_node = index_node.next
                    i+=1
                index_node.prev.next = index_node.next
        else:
            if index == -1:
                self.tail = self.tail.prev
                self.tail.next = None
            else:
                i = -1
                index_node = self.tail
                while i > index and index_node.prev is not None:
                    index_node = index_node.prev
                    i-=1
                index_node.next.prev = index_node.prev
                index_node.prev.next = index_node.next

    # to remove the value 
    def remove_value(self, value):
        index_node = self.head
        while index_node is not None:
            if index_node.data == value:
                if index_node.prev is not None:
                    index_node.prev.next = index_node.next
                else:
                    index_node.next.prev = None
                    self.head = index_node.next
                if index_node.next is not None:
                    index_node.next.prev = index_node.prev
            index_node = index_node.next

dd = DoubleLinkedList()
dd.add_begin(10)
dd.add_begin(20)
dd.add_begin(30)
dd.add_end(40)
dd.add_end(50)
dd.update(50, 60)
dd.remove_value(30)
dd.remove_index(-2)
dd.display(-1)

        