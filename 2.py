import heapq
class node:
	def __init__(self, freq, symbol, left=None, right=None):
		self.freq = freq
		self.symbol = symbol
		self.left = left
		self.right = right
		self.huff = ' '
	def __lt__(self, nxt):
		return self.freq < nxt.freq
def printNodes(node, val=''):
	newVal = val + str(node.huff)
	if(node.left):
		printNodes(node.left, newVal)
	if(node.right):
		printNodes(node.right, newVal)
	if(not node.left and not node.right):
		print(node.symbol+ " -> "+newVal)
		
def check(c=[]):
	for i in range(0,len(c)):
		for j in range (i+1,len (c)):
			if c[i]==c[j]:
				print("you entered two similar elements")
				exit(0)
			else:
				continue
chars =[]
freq = []
nodes = []
a=int(input("ENTER NO. OF ELEMENTS TO CREATE HUFFMAN CODE\t"))
print("enter elements")
for j in range (a):
	chars.append(input())
	check(chars)	

print("enter frequencies")
for k in range(a):
	freq.append(int(input()))
for x in range(len(chars)):
	heapq.heappush(nodes, node(freq[x], chars[x]))
while len(nodes) > 1:
	left = heapq.heappop(nodes)
	right = heapq.heappop(nodes)

	left.huff = 0
	right.huff = 1

	newNode = node(left.freq+right.freq, left.symbol+right.symbol, left, right)
	heapq.heappush(nodes, newNode)
printNodes(nodes[0])