class Node:
	def __init__(self, data):
		self.prev = None
		self.data = data
		self.next = None

class DoubleLinked:
	def __init__(self):
		self.tail = None
		self.head = None
	
	def add_value(self, data):
		new_node = Node(data)
		if self.head is None:
			self.head = new_node
			self.tail = new_node
		else:
			self.tail.next = new_node
			new_node.prev = self.tail
			self.tail = new_node

	def remove_value(self):
		if self.head is None:
			print('queue is empty..')
		else:
			if self.head.next is None:
				self.head = None
			else:
				self.head = self.head.next
				self.head.prev = None
			
	def queue_length(self):
		length = 0
		index_node = self.head
		while index_node is not None:
			length += 1
			index_node = index_node.next
		print(f'length of queue is: {length}')

	def display(self):
		index_node = self.head
		while index_node is not None:
			print(index_node.data)
			index_node = index_node.next
	
dd = DoubleLinked()

while True:
	print('''
		1. To add to queue.
	   	2. To remove from queue.
	   	3. To find the length of queue.
	   	4. To display the queue
	   	5. To quit
''')
	response = eval(input('Enter your choice: '))

	if response == 1:
		dd.add_value(eval(input('Enter the data: ')))
	elif response == 2:
		dd.remove_value()
	elif response == 3:
		dd.queue_length()
	elif response == 4:
		dd.display()
	elif response == 5:
		break
	else:
		print('Enter the correct option...')