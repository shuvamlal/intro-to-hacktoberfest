/*Ugly numbers are numbers whose only prime factors are 2, 3 or 5.

The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included.
Task: Given a number n, we have to find n’th Ugly number.


because every number can only be divided by 2, 3, 5, one way to look at the sequence is to split the sequence to three groups as below:
     (1) 1×2, 2×2, 3×2, 4×2, 5×2, …
     (2) 1×3, 2×3, 3×3, 4×3, 5×3, …
     (3) 1×5, 2×5, 3×5, 4×5, 5×5, …

     We can find that every subsequence is the ugly-sequence itself (1, 2, 3, 4, 5, …) multiply 2, 3, 5. 
     Then we use similar merge method as merge sort, to get every ugly number from the three subsequence.
     Every step we choose the smallest one, and move one step after.
*/

/*Code using dynamic programming.. 
Time Complexity: O(n)
*/
# include<bits/stdc++.h> 
using namespace std; 

/* Function to get the nth ugly number*/
unsigned getNthUglyNo(unsigned n) 
{ 
	unsigned ugly[n]; // To store ugly numbers 
	unsigned i2 = 0, i3 = 0, i5 = 0; 
	unsigned next_multiple_of_2 = 2; 
	unsigned next_multiple_of_3 = 3; 
	unsigned next_multiple_of_5 = 5; 
	unsigned next_ugly_no = 1; 

	ugly[0] = 1; 
	for (int i=1; i<n; i++) 
	{ 
	next_ugly_no = min(next_multiple_of_2, 
						min(next_multiple_of_3, 
							next_multiple_of_5)); 
	ugly[i] = next_ugly_no; 
	if (next_ugly_no == next_multiple_of_2) 
	{ 
		i2 = i2+1; 
		next_multiple_of_2 = ugly[i2]*2; 
	} 
	if (next_ugly_no == next_multiple_of_3) 
	{ 
		i3 = i3+1; 
		next_multiple_of_3 = ugly[i3]*3; 
	} 
	if (next_ugly_no == next_multiple_of_5) 
	{ 
		i5 = i5+1; 
		next_multiple_of_5 = ugly[i5]*5; 
	} 
	} /*End of for loop (i=1; i<n; i++) */
	return next_ugly_no; 
} 

/* Driver program to test above functions */
int main() 
{ 
	int n = 150; 
	cout << getNthUglyNo(n); 
	return 0; 
} 
