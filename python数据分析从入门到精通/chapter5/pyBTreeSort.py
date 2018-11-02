#-*- coding:utf-8 -*-
#file:pyBTreeSort.py
#
'''
先对数据进行二叉树的构建，
当树构建好以后，对树进行中序遍历，得到的结果就是从小到大进行排序的结果
如果要从大到小进行排序，则可以先从右子树开始进行中序遍历
'''
class BTree():
	def __init__(self,value):
		self.data = value
		self.left = None
		self.right = None
	def insertLeft(self,value):
		self.left = BTree(value)
		return self.left
	def insertRight(self,value):
		self.right = BTree(value)
		return self.right
	def show(self):
		print(self.data)
def inorder(node):
	if node.left is not None:
		inorder(node.left)
	node.show()
	if node.right is not None :
		inorder(node.right)
def rinorder(node):
	if node.data:
		if node.right:
			rinorder(node.right)
		node.show()
		if node.left:
			rinorder(node.left)
def insert(node,value):
	if value > node.data:
		if node.right:	
			insert(node.right,value)
		else:
			node.insertRight(value)
	else:
		if node.left:
			insert(node.left,value)
		else:
			node.insertLeft(value)
if __name__ == '__main__':
	l = [3,5,7,20,43,2,15,30]
	Root = BTree(l[0])
	node = Root
	for i in range(1,len(l)):
		insert(node,l[i])
	print('******************************************')
	print('               从小到大    ')
	print('*********************************************')
	inorder(Root)

	print('******************************************')
	print('               从大到小    ')
	print('*********************************************')
	rinorder(Root)

