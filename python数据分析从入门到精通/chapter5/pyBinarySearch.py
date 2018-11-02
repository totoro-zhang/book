#-*- coding:utf-8 -*-
#file:pyBinarySearch.py
#

def BinarySearch(l,key):
	low = 0
	high = len(l)-1
	times = 0
	while(low <= high):
		mid = (low + high) // 2
		times = times +1
		if(l[mid] < key):
			low = mid + 1
		elif(l[mid] > key):
			high = mid -1
		else:
			print('use %d time(s)'% times)
			return mid
	return -1
if __name__ == '__main__':
	l=[1,5,6,9,10,51,62,65,70]
	print(BinarySearch(l,5))
	print(BinarySearch(l,10))
	print(BinarySearch(l,65))
	print(BinarySearch(l,70))
	print(BinarySearch(l,80))

