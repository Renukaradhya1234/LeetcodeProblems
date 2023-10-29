class Node:
	def __init__(self, data):
		self.prev = None
		self.data = data
		self.next = None

class DoubleLinked:
	def __init__(self):
		self.head = None
		self.tail = None
	
	def add_end(self, data):
		new_node = Node(data)
		if self.head is None:
			self.head = new_node
			self.tail = new_node
		else:
			self.tail.next = new_node
			new_node.prev = self.tail
			self.tail = new_node

	def remove_end(self):
		if self.head is None:
			print('stack empty...')
		else:
			print(f'removed data is: {self.tail.data}')
			self.tail = self.tail.prev
			if self.tail is None:
				self.head = self.tail
			else:
				self.tail.next = None
			

	def stack_length(self):
		length = 0
		index_node = self.head
		while index_node is not None:
			length += 1
			index_node = index_node.next
		print(f'Length of stack is: {length}')
		return length

	def display(self, reverse):
		index_node = self.head
		if self.stack_length() > 0:
			if reverse == 1 :
				while index_node is not None:
					print(index_node.data)
					index_node = index_node.next
			else:
				index_node = self.tail
				while index_node is not None:
					print(index_node.data)
					index_node = index_node.prev
		else:
			print('Stack is Empty...')

dd = DoubleLinked()

while True:
	print('''
				1. To add to stack.
				2. To remove from stack.
				3. To find the length.
				4. To display the stack.
	   			5. To quit.
''')
	response = eval(input('Enter your choice: '))
	
	if response == 1:
		dd.add_end(eval(input('Enter the data: ')))
	elif response == 2:
		dd.remove_end()
	elif response == 3:
		dd.stack_length()
	elif response == 4:
		print('''
							1. To print in order
							2. To print revers order
''')
		dd.display(eval(input('Enter your choice: ')))
	elif response == 5:
		break
	else:
		print('Enter the correct number...')