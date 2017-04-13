import copy

class Node():
	def __init__(self, label, color ):
		self.label = label
		self.color = color

	def __str__(self):
		return str( "("+str(self.label)+ " "+ str(self.color)+")")

	def __eq__(self, another):
		return hasattr(another, 'label') and self.label == another.label and hasattr(another, 'color') and self.color == another.color
	
	def __hash__(self):
		return hash(self.label)
		
	def printNode(self):
		print self.label, self.color,

class Graph():
	def __init__(self):
		self.AdjDict = {} 

	def addVertice(self, u, v):
		if u in self.AdjDict:
			self.AdjDict[u].append(v)
		else:
			self.AdjDict[u] = []
			self.AdjDict[u].append(v);
			

	def printGraph(self):
		node = Node('0', 'x')
		for node in self.AdjDict:
	
			print  str(node), ": ",
			for j in self.AdjDict[node]:
				print str(j), 
			print ""

	def visitNode(self, u, newcolor):
		self.AdjDict[u].color = newcolor

	def DepthFirstSearch(self, initialNode):
		stack = [initialNode]
		graphCopy = copy.deepcopy(self)
		visited = {}

		while len(stack) != 0:
			topNode = stack.pop()
			if topNode not in visited:
				newNode = Node(topNode.label, 'G')
				visited[newNode] = 1
				# print "antigo:", str(topNode), "novo:", str(newNode)
				try:
					graphCopy.AdjDict[newNode] = graphCopy.AdjDict.pop(topNode)
				except:
					graphCopy.AdjDict[topNode] = []
				
				for key in graphCopy.AdjDict:
					for item in graphCopy.AdjDict[key]:
						if item == topNode:
							graphCopy.AdjDict[key].remove(item)
							graphCopy.AdjDict[key].append(newNode)
				try:
					stack.extend( x for x in graphCopy.AdjDict[newNode] if x not in visited and x not in stack)
				except:
					pass

		for i in graphCopy.AdjDict :
			if( i.color == 'W'):
				return 0
			else:
				for j in graphCopy.AdjDict[i]:
					if( j.color == 'W' ):
						return 0

		return 1
		



def main():
	line = raw_input()
	line = line.split(" ")
	numIntersecoes = int(line[0])
	numRuas = int(line[1])

	while numIntersecoes and numRuas :
		graph = Graph()
		for i in range(0, numRuas):
			line = raw_input()
			line = line.split(" ")
			
			nodeU = Node( int(line[0]), 'W' )
			nodeV = Node( int(line[1]), 'W' )

			graph.addVertice(nodeU, nodeV)
			if( int(line[2]) == 2):
				graph.addVertice(nodeV, nodeU)

		for i in graph.AdjDict:
			result = graph.DepthFirstSearch( i )
			if not result:
				break

			break

		print result

		line = raw_input()
		line = line.split(" ")
		numIntersecoes = int(line[0])
		numRuas = int(line[1])


main()

