"""
Newman-Conway Sequence is the one which generates the following integer sequence.
1 1 2 2 3 4 4 4 5 6 7 7…

In mathematical terms, the sequence P(n) of Newman-Conway numbers is defined by recurrence relation

P(n) = P(P(n - 1)) + P(n - P(n - 1)) 
with seed values P(1) = 1 and P(2) = 1

Task:Given a number n, print n-th number in Newman-Conway Sequence
"""

''' Python program to find the n-th element of 
	Newman-Conway Sequence'''
  #Time Complexity : O(n) 


# To declare array import module array 
import array 
def sequence(n): 
	f = array.array('i', [0, 1, 1]) 

	# To store values of sequence in array 
	for i in range(3, n + 1): 
		r = f[f[i-1]]+f[i-f[i-1]] 
		f.append(r); 

	return r 

# Driver code 
def main(): 
	n = 10
	print sequence(n) 
	
if __name__ == '__main__': 
	main() 
